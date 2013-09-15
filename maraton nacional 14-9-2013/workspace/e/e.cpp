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

const int MAXS = 200;

map<vector<int>, string> mat [MAXS+5][MAXS+5];


void clearmat () {
    for (int i = 0; i < MAXS+5; ++i) {
        for (int j = 0; j < MAXS+5; ++j) {
            mat[i][j].clear();   
        }   
    }
}

vector<int> process (string &s) {
    vector<int> ret(30,0);
    for (int i = 0; i < s.size(); ++i) {
        ret[s[i]-'a']++;   
    }   
    return ret;
}

void addmat (string &s) {
    stringstream ss;
    ss << s;
    while(ss>>s) {
        vector<int> v = process(s);
        if (!mat[s[0]][s[s.size()-1]].count(v)){
            mat[s[0]][s[s.size()-1]][process(s)] = s;
        }
    }   
}

void solve(string &s) {
    stringstream ss;
    vector<string> vs;
    ss << s;
    while(ss >> s) {
        vector<int> v = process(s);
        if (!mat[s[0]][s[s.size()-1]].count(v)) {
            vs.push_back(s);
        }
        
        else {
            vs.push_back(mat[s[0]][s[s.size()-1]][v]);   
        }
    }
    for (int i = 0; i < vs.size(); ++i) {
        if (i) {
            cout<<" ";   
        }   
        cout<<vs[i];
    }
    cout<<endl;
}

int main (){
    int n;
    cin>>n;
    string s;
    getline(cin,s);
    while(n--) {
        getline(cin,s);
        clearmat();
        addmat(s);
        getline(cin,s);
        solve(s);
    }
    return 0;
}
