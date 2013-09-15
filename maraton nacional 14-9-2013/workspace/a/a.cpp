using namespace std;

#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <climits>
#include <stack>
#include <map>
#include <set>

#define D(x) cout << #x " = " << (x) << endl


const double EPS = 1e-9;

int cmp(double x, double y =0, double tol = EPS){
    return (x <= y +tol)? (x+tol < y)? -1 : 0 : 1;
}

struct MCMF {
    typedef int ctype;
    enum {MAXN = 1000, INF = INT_MAX};
    struct Edge {int x,y; ctype cap, cost;};
    vector<Edge> E; vector<int> adj[MAXN];
    int N, prev[MAXN]; ctype dist [MAXN], phi[MAXN];
    MCMF(int NN) : N(NN) {}

    void add (int x, int y, ctype cap, ctype cost) {
//        Edge e1 = {x,y,cap,cost}, e2 = {y,x,0,-cost};
        Edge e1,e2;
        e1.x = x; e1.y = y; e1.cap = cap; e1.cost = cost;
        e2.x = y; e2.y = x; e2.cap = 0; e2.cost = -cost;
        adj[e1.x].push_back(E.size()); E.push_back(e1);
        adj[e2.x].push_back(E.size()); E.push_back(e2);
    }

    void mcmf(int s, int t, ctype &flowVal, ctype &flowCost) {
        int x;
        flowVal = flowCost = 0; memset(phi,0,sizeof phi);
        while(true) {
            for (x = 0; x < N; x++) prev[x] = -1;
            for (x = 0; x < N; ++x) dist[x] = INF;
            dist[s] = prev[s] = 0;

            set<pair<ctype,int> > Q;
            Q.insert(make_pair(dist[s],s));
            while(!Q.empty()) {
                x = Q.begin()->second; Q.erase(Q.begin());
                for( vector<int>::iterator it = adj[x].begin(); it != adj[x].end(); ++it) {
                    const Edge &e = E[*it];
                    if (e.cap <= 0) continue;
                    ctype cc = e.cost+phi[x] - phi[e.y];
                    if (dist[x] + cc<dist[e.y]) {
                        Q.erase(make_pair(dist[e.y], e.y));
                        dist[e.y] = dist[x] + cc;
                        prev[e.y] = *it;
                        Q.insert(make_pair(dist[e.y],e.y));
                    }
                }
            }
            if (prev[t] == -1) break;
            ctype z = INF;
            for (x = t; x != s; x = E[prev[x]].x) z = min(z, E[prev[x]].cap);
            for (x = t; x != s; x = E[prev[x]].x)
                { E[prev[x]].cap -= z; E[prev[x]^1].cap += z;}
            flowVal += z;
            flowCost += z*(dist[t] - phi[s] + phi[t]);
            for (x = 0; x < N; ++x) if (prev[x] != -1) phi[x] += dist[x];
        }
    }
};

int r,n;

int mapa [2][105][2];

int dist (int i, int j) {
    return abs(mapa[0][i][0]-mapa[1][j][0]) + abs(mapa[0][i][1] - mapa[1][j][1]);
}

int main (){
    while(cin>>r>>n) {

        for (int i = 0; i < r; ++i) {
            cin>>mapa[0][i][0]>>mapa[0][i][1];
        }
        for (int i = 0; i < n; ++i) {
            cin>>mapa[1][i][0]>>mapa[1][i][1];
        }
        MCMF mcmf (r+n+2);
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < n; ++j) {
                int d = dist(i,j);
                mcmf.add(i+1,j+r+1,1,d);
            }
        }
        for (int i = 0; i < r; ++i) {
            mcmf.add(0,i+1,1,0);
        }
        for (int i = 0; i < n; ++i) {
            mcmf.add(i+r+1,r+n+1,1,0);
        }
        int val,cost;
        mcmf.mcmf(0,r+n+1,val,cost);
        assert(val == n);
        cout<<cost<<endl;
    }
    return 0;
}
