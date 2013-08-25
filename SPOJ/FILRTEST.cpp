#include <cstring>
#include <cstdio>
#include <cstdlib>


int arr [1500000];
char s [1500000]; 
int size;

void kmp () {
  arr [0] = 0;
  int i,j;
  for (i = 2, j = 0; i <= size;) {
    if (s[i-1]==s[j]) arr[i++] = ++j; else if (j > 0) j = arr[j]; else arr[i++] = 0;
  }
}


int main () {
  int n;
  while(scanf("%d",&n)) {
    if (n == -1) break;
    gets(s);
    size = strlen(s);
    if (n < size) {
      continue;
    }
    kmp();
    int len = size-arr[size];

    //    printf("len = %d\n",len);
    printf("%d\n",(((n-size)/len)+1));
  }
}
