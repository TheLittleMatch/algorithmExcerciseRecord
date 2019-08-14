#include <stdio.h>
#include <stdlib.h>
int main() {
  int data[101], right[101];
  int i, n, t, len;

  scanf("%d ", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", data[i]);
  }
  len = n;
  //初始化
  for (i = 1; i <= n; i++) {
    if (i != n) {
      right[i] = i + 1;
    } else {
      right[i] = 0;
    }
    //直接在数组data末尾加一个数
    len++;
    scanf("%d", &data[len]);

    //从链表头部开始遍历
    t = 1;
    while (t != 0) {
    }
  }

  return 0;
}