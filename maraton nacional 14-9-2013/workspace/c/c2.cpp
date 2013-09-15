       using namespace std;

#define _GLIBCXX_DEBUG
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
#include <stack>
#include <map>
#include <set>

#define D(x) cout << #x " = " << (x) << endl

#define For(i,a,b) for(int i = (a); i < (b); ++i)

const double EPS = 1e-9;

int cmp(double x, double y =0, double tol = EPS){
    return (x <= y +tol)? (x+tol < y)? -1 : 0 : 1;
}

int p [7][6], p2 [7][6];

int arr [7] =  {0,1,2,3,4,5,6};

void find_ (int where, int what) {
    
       int i;
       for (i = 0; i < 6; ++i) {
            if (p2[where][i] == what) break;   
        }
        assert( i < 6);
        rotate(p2[where],p2[where]+i,p2[where]+6);
        assert(p2[where][0] == what);
}

int next(int n) {
    return (n+1)%6;   
}
int prev (int n){
    return (n-1+6)%6;   
}

bool can () {
//    if (arr[0] != 5) return false;
//    if (arr[1] != 2) return false;
//    if (arr[2] != 4) return false;
//    if (arr[3] != 1 or arr[4] != 0 or arr[5]!= 6 or arr[6]!= 3) return false;
    for (int i = 0; i < 6; ++i) {
         find_(arr[i+1],p[arr[0]][i]);
    }
//    for (int i = 0; i < 7; ++i) {
//        for (int j = 0; j < 7; ++j) {
//            cout<<p[i][j]<<" ";   
//        }   
//        cout<<endl;
//    }
        bool could = true;
         for (int j = 1; j < 7; ++j) {
                could = could && (p2[arr[j]][1] == p2[next(arr[j])][5]);
                could = could && (p2[arr[j]][5] == p2[prev(arr[j])][1]);
         }
    return could;
}

int main (){
    
    while(cin>>p[0][0]) {
        for (int i = 0; i < 7; ++i) {
            for (int j = 0; j < 6; ++j) {
                if (i || j){
                    cin>>p[i][j]; 
                    p2[i][j] = p[i][j];  
                }
            }
        }
        bool could = false;
        do {
            if (can()) {
                puts("YES");
                could = true;
                break;
            }
        }while(next_permutation(arr,arr+7));
        if (!could) puts("NO");
    }
    return 0;
}
