#include <stdio.h>
int main() {
  int q[102] = {0, 6, 3, 1, 7, 5, 8, 9, 2, 4}, head, tail;
  int i;
  // initial queue

  head = 1;
  tail = 10; // tail指向最后一个
  while (head < tail) {
    //打印队首并将队首出队
    printf("%d ", q[head]);
    head++;

    //先将队首的数添加到队尾
    q[tail] = q[head];
    tail++;
    //再将队首出队
    head++;
  }

  getchar();
  getchar();
  return 0;
}