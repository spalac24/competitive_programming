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

const int MAXN = 100000;
long long dp[MAXN];
long long a[MAXN];

int main (){
    string line;
    while (getline(cin, line)){
        stringstream ss(line);
        int n = 0;
        while(ss >> a[n]) n++;
        dp[0] = 0;
        for (int i = 1; i <= n; ++i){
            dp[i] = max(dp[i-1] + a[i-1], a[i-1]);        
        }
        
        long long best = 0;
        for (int i = 1; i <= n; ++i){
            best = max(dp[i], best);       
        }
        cout << best << endl;
    }
    return 0;
}
