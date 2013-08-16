using namespace std;
# include <algorithm>
# include <iostream>
# include <iterator>
# include <sstream>
# include <fstream>
# include <cassert>
# include <cstdlib>
# include <string>
# include <cstring>
# include <cstdio>
# include <vector>
# include <cmath>
# include <queue>
# include <stack>
# include <map>
# include <set>

#define For(i, a, b) for (int i = (a); i < (b); i++)
#define foreach(x, v) for (typeof (v).begin() x = (v).begin(); x != v.end(); x++)
#define D(x) cout << #x  " = " << (x) << endl

const double EPS = 1e-9;
int cmp (double x, double y = 0, double tol = EPS){
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

string mat [10][5] = {
{
    " - ",
    "| |",
    "   ",
    "| |",
    " - "
},    
{
    "   ",
    "  |",
    "   ",
    "  |",
    "   "
},
{
    " - ",
    "  |",
    " - ",
    "|  ",
    " - "
},
{
    " - ",
    "  |",
    " - ",
    "  |",
    " - "
},

{
    "   ",
    "| |",
    " - ",
    "  |",
    "   "
},


{
    " - ",
    "|  ",
    " - ",
    "  |",
    " - "
},
{
    " - ",
    "|  ",
    " - ",
    "| |",
    " - "
},
{
    " - ",
    "  |",
    "   ",
    "  |",
    "   "
},
{
    " - ",
    "| |",
    " - ",
    "| |",
    " - "
},
{
    " - ",
    "| |",
    " - ",
    "  |",
    " - "
}
};


string hexpand (string s, int n) {
    string r;
    r += s[0];
    for (int i = 0; i < n; ++i)
        r += s[1];
    r += s[2];
    return r;
}

int main () {
    int n;
    string s;
    string out;
    while(cin>>n>>s) {
        if (n == 0) break;
        out = "";
        for (int j = 0; j < s.size(); ++j) {
             int d = s[j]-'0';
             out += hexpand(mat[d][0],n);
             if (j != s.size()-1) out += " ";
        }
        cout<<out<<endl;
        for (int k = 0; k < n; ++k) {   
            out = "";
            for (int j = 0; j < s.size(); ++j) {
                 int d = s[j]-'0';
                 out += hexpand(mat[d][1],n);
                 if (j != s.size()-1) out += " ";
            }  
            
            cout<<out<<endl; 
        }
        out = "";
        for (int j = 0; j < s.size(); ++j) {
             int d = s[j]-'0';
             out += hexpand(mat[d][2],n);
             if (j != s.size()-1) out += " ";
        }
        cout<<out<<endl;
        for (int k = 0; k < n; ++k) {   
            out = "";
            for (int j = 0; j < s.size(); ++j) {
                 int d = s[j]-'0';
                 out += hexpand(mat[d][3],n);
                 if (j != s.size()-1) out += " ";
            }  
            
            cout<<out<<endl; 
        }
        out = "";
        for (int j = 0; j < s.size(); ++j) {
             int d = s[j]-'0';
             out += hexpand(mat[d][4],n);
             if (j != s.size()-1) out += " ";
        }
        cout<<out<<endl;
        cout<<endl;
    }
}
