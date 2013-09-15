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

int n;
string s;

int process(int i){
    if (i >= n) return n+1;
    if (s[i] == '0') return i;
    return process(process(i+1)+1);    
}

int main (){
    ios::sync_with_stdio(false);
    while (cin >> s){
        n = s.size();
        for (int i = 0; i < n; ++i){
            if (s[i] == '?') s[i] = '0';    
        }
        int i = 0;
        int ans = 0;
        while (true){
            i = process(i);
            ans++;
            if (i == n-1) break;
            if (i >= n){
                ans = 0;
                break;    
            }
            i++;
        }
        cout << ans << endl;
    }
    
    return 0;
}
