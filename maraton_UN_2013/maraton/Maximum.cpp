#include <iostream>
#include <cstdio>

using namespace std;

typedef unsigned long long ull;

ull fac [24];
ull choose [24][24];


ull f(ull n,ull k) {
    if (k == 1) {
        return fac[n-1];
    }
    ull ret = 0;
    for (int i = 2; i <= k; ++i) {
        for (int j = 0; j <= i-2; ++j) {
            ret += fac[j]*choose[k-2][j]*fac[i-j-2]*choose[k-2-j][i-j-2]*fac[n-i];
    //        cout<<ret<<endl;
        }
    }
    return ret;
}


int main  () {
    fac[0] = 1;
    for (ull i = 1; i < 24; ++i) {
        fac[i] = fac[i-1]*i;
    }
    for (int i = 0; i < 24; ++i)choose[i][0] = 1;
    for (int i = 0; i < 24; ++i)choose[i][i] = 1;


    for (int i = 1; i < 24; ++i){
        for (int j = 1; j < i; ++j) {
            choose[i][j] = choose[i-1][j] + choose[i-1][j-1];
        }
    }
    int n;
    ull cas;
    cin>>cas;
    while(cas--) {
        ull m,n,k;
        cin>>m>>n>>k;
        ull r = f(n,k);
        cout<<m<<" "<<r<<endl;
    }
}
