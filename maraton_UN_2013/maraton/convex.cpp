#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;


typedef long long CoordType;


struct point {
    CoordType x,y;
    point(){}
    point(CoordType a, CoordType b): x(a), y(b) {}
    bool operator < (const point &p) const {
        return y < p.y || (y == p.x && y < p.x);
    }

    bool operator == ( point p)  {
        return x == p.x and y == p.y;
    }
};

point pivot;

inline int distsqr (const point &a, const point &b) {
    return (a.x - b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

inline double dist (const point &a, const point &b) {
    return sqrt(distsqr(a,b));
}

inline int cross(const point &a, const point &b, const point &c) {
    return (b.x - a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
}

bool angleCmp (const point &self, const point &that) {
    int t = cross(pivot,that,self);
    if (t < 0) return true;
    if (t == 0) {
            return (distsqr(pivot,self) < distsqr(pivot,that));
    }
    return false;
}


typedef vector<point> poly;

bool mfunc (const point &a, const point &b)  {
    return a.y < b.y || (a.y == b.y and a.x > b.x);
}
poly graham (poly p) {


    for (int i = 1; i < p.size(); ++i) {
        if (p[i] < p[0])
                swap(p[0],p[i]);
    }
    pivot = p[0];
    sort(p.begin(),p.end(),angleCmp);

    poly chull (p.begin(),p.begin()+3);

    for (int i = 3; i < p.size(); ++i) {

        while(chull.size()>=2 && cross(chull[chull.size()-2],chull[chull.size()-1],p[i]) <= 0) {

            chull.erase(chull.end()-1);
        }
        chull.push_back(p[i]);
    }
    return chull;

}

void mprint (poly &P) {
    int mmax = 0;
    int n = P.size();
    cout<<n<<endl;
    for (int i = 1; i < n; ++i ) {

        if (mfunc(P[mmax], P[i])) {
            mmax = i;
        }
    }
    //cout<<mmax<<endl;
    cout<<P[mmax].x<<" "<<P[mmax].y<<endl;
    int i = (mmax-1+n)%n;
    while(i != mmax) {
      //  cout<<i<<endl;
        cout<<P[i].x<<" "<<P[i].y;
        cout<<endl;
        i = (i-1+n)%n;
    }
}

int main () {
    int cases;
    cin>>cases;
    while(cases--) {
        int n,m;
        cin>>m>>n;
        cout<<m<<" ";
        poly P (n);
        for (int i = 0; i < n; ++i) {
            cin>>P[i].x>>P[i].y;
        }
        P = graham(P);
        if (P.size() == 3) {
            if (cross(P[0],P[1],P[2]) == 0) {
                P.erase(P.begin()+1);
            }
        }
        mprint(P);
      //  cout<<" __ "<<endl;
    }
}

