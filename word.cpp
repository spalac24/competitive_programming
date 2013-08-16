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

string reverse (string s) {
	string r;
	for (int i = s.size()-1; i >= 0; --i) 
		r += s[i];
	return r;
}

int main () {
	string s;
	while(getline(cin,s)) {
		stringstream ss (s);
		string s2;
		bool first = true;
		while(ss>>s2) {
			if (!first) {
				cout<<" ";
			}
			first = false;
			cout<<reverse(s2);
		}
		cout<<endl;
	}
}
