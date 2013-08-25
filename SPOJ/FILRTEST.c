#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int arr [1500000];
char s [1500000];
int size;

void kmp () {
  arr [0] = 0;
  int i,j;
  for (i = 1; i < size; ++i) {
    j = arr[i-1];
    while(j > 0 && s[i] != s[j]) j = arr[j];
    if (s[i] == s[j]) ++j;
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
    if (s[size-1] == '\n') --size;

    if (n < size) {
      printf("0\n");
      continue;
    }
    kmp();
    int len = size-arr[size-1];

    //    for (int i = 0; i < size; ++i) { cout<<arr[i]<<endl;}
    n -= size;
    //  printf("size = %d, n = %d\n",size,n);
    printf("%d\n",((n/len)+1));
  }
}
