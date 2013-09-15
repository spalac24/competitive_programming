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

vector<int> process (string s) {
    vector<int> v(30,0);
    for (int i = 0; i < s.size(); ++i) {
        v[s[i]-'a']++;   
    }   
    return v;
}


const int MAXN = 500;

bool g [MAXN+5][MAXN+5];
vector<int> prep [MAXN+5][2];

void print (vector<int> t) {
    for (int i = 0; i < t.size(); ++i) cout<<t[i]<<" ";
    cout<<endl;   
}

bool beats(int x, int y) {
  //  cout<<x<<" : ";
 //   print(prep[x][0]);
  //  cout<<y<<" : ";
  //  print(prep[y][1]);
    assert(prep[x][0].size() == 30);
    for (int i = 0;(i < 30); ++i) {
       if (prep[x][0][i] < prep[y][1][i]) return false;
    }   
    return true;
}

void print_g (int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout<<g[i][j];   
        }   
        cout<<endl;
    }   
}

bool seen[MAXN+5];
int L,R,matchL[MAXN+5],matchR[MAXN+5];

bool assign(int i) {
    for (int j = 0; j < R; ++j) if (g[i][j] and !seen[j]) {
        seen[j] = true;
        if (matchR[j] < 0 or assign(matchR[j]))
            return matchL[i] = j, matchR[j] = i, true;   
    }
    return false;
}

int maxBipartiteMatching() {
    for (int i = 0; i < L; ++i) matchL[i] = -1;
    for (int j = 0; j < R; ++j) matchR[j] = -1;
    int ans = 0;
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < R; ++j) seen[j] = false;
        if (assign(i)) ++ans;
    }   
    return ans;
}



int main (){
    int n,m;
    while(cin>>n>>m) {
        L = n;
        R = m;
        string s;
           for (int i = 0; i < n; ++i) {
                cin>>s;
                prep[i][0] = process(s);
            }
            for (int i = 0; i < m; ++i) {
                cin>>s;
                prep[i][1] = process(s);
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    g[i][j] = beats(i,j);   
                }
            }
            //print_g(n,m);
            cout<<maxBipartiteMatching()<<endl;
    }
    return 0;
}
