#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdio>

using namespace std;

int arr [2000000];
char s [2000000];
int size;

void kmp () {
  arr [0] = 0;
  for (int i = 1; i < size; ++i) {
    int j = arr[i-1];
    while(j > 0 and s[i] != s[j]) j = arr[j];
    if (s[i] == s[j]) j++;
    arr[i] = j;
  }
}

int main () {
  int n;
  while(scanf("%d",&n)) {
    scanf("%s",s);
    if (n == -1) break;
    size = strlen(s);
    

    if (n < size) {
      printf("0\n");
      continue;
    }
    kmp();
    int len = size-arr[size-1];
    n -= size;
    printf("%d\n",((n/len)+1));
  }
}