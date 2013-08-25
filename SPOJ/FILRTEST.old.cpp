#include <cstring>
#include <cstdio>
#include <cstdlib>


int arr [1500000];
char s [1500000];
int size;

void kmp () {

  int i,j;
  j = arr [0] = 0;
  for (i = 1; i < size;i++) {
    for(;s[i] != s[j] && j > 0 ;) j = arr[j];
    if (j || s[i]==s[j]) arr[i] = ++j;
    arr[i] = j;
  }
}


int main () {
  int n;
  while(scanf("%d",&n)) {
    getchar_unlocked();
    if (n == -1) break;
    gets(s);
    size = strlen(s);
    if (n < size) {
      continue;
    }
    kmp();
    int len = size-arr[size-1];
    printf("%d\n",(((n-size)/len)+1));
  }
}
