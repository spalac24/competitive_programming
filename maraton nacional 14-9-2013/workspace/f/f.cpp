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

const double EPS = 1e-9;

int cmp(double x, double y =0, double tol = EPS){
    return (x <= y +tol)? (x+tol < y)? -1 : 0 : 1;
}

const int MAXN = 1100;
int next[MAXN];
int prev[MAXN];
int seen[MAXN];
int a[MAXN];

int cycle_length(int i){
    if (seen[i] == 1) return 0;
    seen[i] = 1;
    return 1 + cycle_length(next[i]);    
}

void rotar(int i, int first){
   //printf("Call rotar(%d)\n", i+1);
   a[i] = a[next[i]];
   if (next[i] != first) rotar(next[i], first);    
}

int main (){
    int n; long long r;
    while (cin >> n >> r){
        for (int i = 0; i < n; ++i){
            cin >> next[i];
            next[i]--;   
            prev[next[i]] = i;
        }
        memset(seen, false, sizeof seen);
        
        for (int i = 0; i < n; ++i) a[i] = i;
        
        for (int i = 0; i < n; ++i){
            if (seen[i] == 0){
                int t = cycle_length(i);//D(t);
                long long times = r % t;
                //D(times);
                for (int j = 0; j < times; ++j){
                    int first = a[i];
                    rotar(i, i);
                    a[prev[i]] = first;
                }
            }       
        }
        
        for (int i = 0; i < n; ++i){
            if (i != 0) cout << " ";
            cout << a[i] + 1;    
        }
        cout << endl;
           
    }

    return 0;
}
