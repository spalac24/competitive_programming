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
       int i = 100;
       for (i = 0; i < 6; ++i) {
            if (p[where][i] == what) break;   
        }
        assert( i < 6);
        for (int times = 0; times < i; ++times){
            int first = p[where][0];
            for (int j = 1; j < 6; ++j){
                p[where][j-1] = p[where][j];   
            }
            p[where][5] = first;
        }
        
        assert(p[where][0] == what);
}

int next(int n) {
    if (n == 6) return 1;
    return (n+1)%7;   
}
int prev (int n){
    if (n == 1) return 6;
    return n-1;   
}

void print(){
        for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 6; ++j) {
            cout<<p[arr[i]][j]<<" ";   
        }   
        cout<<endl;
    }
}

bool can () {
   // if (arr[0] != 5 or arr[6] != 2 or arr[1] != 4 or arr[2] != 1 or arr[3] != 0 or arr[4] != 6 or arr[5] != 3) return false;
//    if (arr[0] != 5) return false;
//    if (arr[2] != 2) return false;
//    if (arr[3] != 4) return false;
//    if (arr[4] != 1 or arr[5] != 0 or arr[6]!= 6 or arr[1]!= 3) return false;

    for (int i = 0; i < 6; ++i) {
         find_(arr[i+1],p[arr[0]][i]);
    }

//    print();
        bool could = true;
         for (int j = 1; j < 7; ++j) {
                
  //       cout<<could<<endl;
                could = could && (p[arr[j]][1] == p[arr[prev(j)]][5]);
                
         }
    return could;
}

int main (){
    
    while(cin>>p[0][0]) {
        for (int i = 0; i < 7; ++i) {
            for (int j = 0; j < 6; ++j) {
                if (i || j){
                    cin>>p[i][j];   
                }
            }
        }
        
        for (int i = 0; i < 7; ++i) arr[i] = i;
        
        bool could = false;
        do {
            if (can()) {
                puts("YES");
                could = true;
                break;
            }
            
            //print();
            //break;
        }while(next_permutation(arr,arr+7));
        if (!could) puts("NO");
    }
    return 0;
}
