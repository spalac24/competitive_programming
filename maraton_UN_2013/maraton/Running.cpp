#include <iostream>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

priority_queue<int> l;
priority_queue<int, vector<int>, greater<int> > r;

void add (int x) {
    if (!l.size()) {
        l.push(x);
        return;
    }
    if (x >= l.top()) {
        r.push(x);
    }
    else {
        l.push(x);
    }
    if (r.size() == l.size()+1) {
        l.push(r.top());
        r.pop();
    }
    else if (l.size() == r.size()+2) {
        r.push(l.top());
        l.pop();
    }
}

int main () {
    int p;
    cin>>p;
    while(p--) {
        int n,m,x;
        while(l.size())l.pop();
        while(r.size())r.pop();
        cin>>m>>n;
        cout<<m<<" "<<((n+1)/2)<<endl;
        int printed = 0;
        for (int i = 1; i <= n; ++i){
            cin>>x;
            add(x);
            if (i & 1) {
                cout<<l.top()<<" ";
                ++printed;
                if (!(printed%10)) {
                    cout<<endl;
                }
            }
        }
        if (printed %10)
        cout<<endl;
    }
}
