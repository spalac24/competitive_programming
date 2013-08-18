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


string mat [4] = {
	"`1234567890-=",
	"QWERTYUIOP[]",
	"ASDFGHJKL;'\\",
	"ZXCVBNM,./"
};

char decode (char c) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < mat[i].size(); ++j) {
			if (c == mat[i][j]) {
				return mat[i][j-1];
			}
		}
	}
	return c;
}

int main () {
	string s;
	while(getline(cin,s)) {
		for (int i = 0; i < s.size(); ++i) {
			s[i] = decode(s[i]);
		}
		cout<<s<<endl;
	}
}

