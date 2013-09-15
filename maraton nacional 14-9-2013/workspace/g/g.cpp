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

int main (){
    int n, a, b;
    while (cin >> n >> a  >> b){
        int round = 0;
        while (a != b){
            round++;
            a = (a + 1) / 2;
            b = (b + 1) / 2;    
        }    
        cout << round << endl;
    }
    return 0;
}
