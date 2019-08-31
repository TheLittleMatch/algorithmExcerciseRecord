#include <stdio.h>
int a[10], book[10], n; //全局变量没有赋值前默认为0，因此不需要为book初始化
void dfs(int step) { // step表示站在第几个盒子前
  int i;
  if (step == n + 1) { //如果站在第n+1个盒子面前，则表示前n个盒子已经放好扑克牌
    //输出一种排列（1～n号盒子中的扑克牌编号）
    for (i = 1; i <= n; i++) {
      printf("%d", a[i]);
    }
    printf("\n");
    return; //返回之前的一步（最后一次调用dfs的地方）
  }
  //此时站在第step个盒子面前，应该放哪张牌呢？
  //按照1,2,3 ...n的顺序一一尝试
  for (i = 1; i <= n; i++) {
    //判断扑克牌i是否还在手上
    if (book[i] == 0) { // book[i]==0表示扑克牌在手上
      //开始尝试使用扑克牌
      a[step] = i; //将i号扑克牌放入到第step个盒子中
      book[i] = 1; //将book[i]设为1,表示i号扑克牌已经不在手上

      //第step个盒子已经放好扑克牌，接下来需要走到下一个盒子面前
      dfs(step + 1); //这里通过函数的递归调用来实现
      //这是非常重要的一步，将刚才尝试的扑克牌收回，才能进行下一次尝试。
      book[i] = 0;
    }
  }
  return;
}
int main() {
  scanf("%d", &n); // n为1～9的整数
  dfs(1);          //首先站在1号小盒子面前
  getchar();
  getchar();
  return 0;
}