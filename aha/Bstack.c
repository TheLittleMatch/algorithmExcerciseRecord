#include <stdio.h>
#include <string.h>
int main() {

  char a[101], s[101];
  int i, len, mid, next, top;
  gets(a);           //读入一行字符
  len = strlen(a);   //求字符串长度
  mid = len / 2 - 1; //求中点

  top = 0;
  for (i = 0; i <= mid; i++) {
    s[++top] = a[i];
  }
  if (len % 2 == 0) {
    next = mid + 1;
  } else {
    next = mid + 2;
  }
  //开始匹配
  for (i = next; i <= len - 1; i++) {
    if (a[i] != s[top]) {
      break;
    }
    top--;
  }

  if (top == 0) {
    printf("YES");
  } else {
    printf("No");
  }
  getchar();
  getchar();

  return 0;
}