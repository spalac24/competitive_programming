#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

long long process(string s) {
    long long ret = 0;
    for (int i = 0; i < s.size(); ++i) {
        ret <<= 1;
        if(s[i] == 'H'){
            ret |= 1;
        }
    }
    return ret;
}

int arr [10];

int main () {
    assert(false);
    int n,m;
    cin>>n;
    while(n--) {
        string s;
        cin>>m;
        cin>>s;
        cout<<m;
        memset(arr,0,sizeof arr);
        long long x = process(s);
        for (int i = 0; i+2 < 40; ++i) {
            arr[(x>>i)&7]++;
            cout<<" "<<arr[i];
        }
        cout<<endl;
    }
}
