#include <stdio.h>
#include <stdlib.h>
int main() {

  int *p;
  p = (int *)malloc(sizeof(int));
  *p = 10;
  printf("%d ", *p);

  getchar();
  getchar();
  return 0;
}