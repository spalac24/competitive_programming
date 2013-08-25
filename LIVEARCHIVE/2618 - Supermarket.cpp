#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

const int MAXM = 100;
const int MAXN = 100000;


//hasta el item , hasta el estante
double dp [MAXM+5][MAXN+5];
bool possible [MAXM+5][MAXN+5];

int lista [MAXM+5];
int item [MAXN+5];
double price [MAXN+5];

double solve (int n, int m) {
  
  for (int i = 0; i <= m; ++i) {
    dp[i][0] = INFINITY;
  }
  for (int i = 0; i <= n; ++i) {
    dp[0][i] = 0;
    possible[0][i] = true;
  }

  for (int i = 1; i <= m; ++i) {
    for(int j = 1; j <= n; ++j) {
      if (possible[i][j-1]) {
	dp[i][j] = dp[i][j-1];
	possible[i][j] = true;
      }
      else {
	possible[i][j] = false;
	dp[i][j] = INFINITY;
      }
      if (lista[i] == item[j]) {
	if (possible[i][j]) {
	  dp[i][j] = min(dp[i][j],dp[i-1][j-1]+price[j]);
	}
	else {
	  if (possible[i-1][j-1]) {
	    dp[i][j] = dp[i-1][j-1]+price[j];
	    possible[i][j] = true;
	  }
	}
      }
    }
  }

 // for (int j = 0; j <= n; ++j) {
 //   for (int i = 0; i <= m; ++i) {
 //     cout<<dp[i][j]<<(possible[i][j]?'*':' ')<<"\t\t";
 //   }
 //   cout<<endl;
 // }
  return dp[m][n];
}

int main () {
  int n,m;
  while(cin>>m>>n) {
    if (n == 0 and m == 0) break;
    for (int i = 1; i <= m; ++i) cin>>lista[i];
    for (int i = 1; i <= n; ++i) {
      cin>>item[i]>>price[i];
    }
    double x = solve(n,m);
    if (possible[m][n]) {
      cout<<fixed<<setprecision(2)<<x<<endl;
    }
    else {
      cout<<"Impossible"<<endl;
    }
  }
}
