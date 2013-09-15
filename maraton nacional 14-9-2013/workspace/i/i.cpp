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

const int MAXN = 1005;
vector <int> g[MAXN];
bool seen[MAXN];
vector <int> topo;

void tsort(int u){
    if (seen[u]) return;
    seen[u] = true;
    for (int i = 0; i < g[u].size(); ++i){
        int v = g[u][i];
        if (!seen[v]) tsort(v);    
    }
    topo.push_back(u);  
}

void print (vector<int> t) {
    for (int i = 0; i < t.size(); ++i) cout<<t[i]<<" ";
    cout<<endl;   
}

void dfs (int n) {
    if (seen[n]) return;
//    cout<<n<<endl;
    seen[n] = true;
    for (int i = 0; i < g[n].size(); ++i) {
           dfs(g[n][i]);
    }   
}

int main (){
    int n, m;
    while (cin >> n >> m){
        n++;
        for (int i = 0; i <= n; ++i){
            g[i].clear();
            seen[i] = false;       
        }
        topo.clear();
        
        for (int i = 0; i < m; ++i){
            int a, b; cin >> a >> b; 
            g[a].push_back(b);   
        }
        
        for (int i = 0; i < n; ++i){
            if (!seen[i]) tsort(i);
               
        }
        reverse(topo.begin(), topo.end()); 
     //   print(topo);
        memset(seen,0,sizeof seen);
        dfs(0);
        int ans = 0;
        for (int i = 0; i < topo.size(); ++i) {
            if (!seen[topo[i]]) {
//                cout<<" __ "<<endl;
                dfs(topo[i]);
                ++ans;
            }
        }
        cout<<ans<<endl;
        
    }
    return 0;
}
