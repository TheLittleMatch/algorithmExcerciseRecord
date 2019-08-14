#include <stdio.h>

struct queue {
  int data[1000];
  int head;
  int tail;
};

struct stack {
  int data[10];
  int top;
};

int main() {
  struct queue q1, q2;
  struct stack s;
  int book[10];
  int i, t;

  //初始化队列
  q1.head = 1;
  q1.tail = 1;
  q2.head = 1;
  q2.tail = 1;

  s.top = 0;
  //标记哪些牌在桌子上了。
  for (i = 1; i <= 9; i++) {
    book[i] = 0;
  }
  //依次向队列中插入6个数
  for (i = 0; i <= 6; i++) {
    scanf("%d", &q1.data[q1.tail]);
    q1.tail++;
  }

  for (i = 0; i <= 6; i++) {
    scanf("%d", &q2.data[q2.tail]);
    q2.tail++;
  }

  while (q1.head < q1.tail && q2.head < q2.tail) {

    t = q1.data[q1.head]; // a出一张牌
    if (book[t] == 0) {   //表明桌上没有牌面为t的牌。
                          // a此轮没有赢牌
      q1.head++;          //已打出的牌出队
      s.top++;
      s.data[s.top] = t; //再把打出的牌放到桌上，即入栈
      book[t] = 1;       //标记桌上已有的牌面为t的牌
    } else {
      // a此轮可以赢牌
      q1.head++; // A打出的牌出队
      q1.data[q1.tail] = t;
      q1.tail++;
      while (s.data[s.top] != t) //把桌上的牌放到手中牌的末尾
      {
        book[s.data[s.top]] = 0;          //取消标记
        q2.data[q2.tail] = s.data[s.top]; //依次放入队尾
        q2.tail++;
        s.top--;
      }
    }
  }
  if (q2.head == q2.tail) {
    printf("A win\n");
    printf("A 手中的牌是：\n");
    for (i = q1.head; i <= q1.tail - 1; i++) {
      printf(" %d", q1.data[i]);
      if (s.top > 0) { //如果桌上有牌则输出桌上的牌
        printf("\n桌上的牌是");
        for (i = 1; i <= s.top; i++) {
          printf(" %d", s.data[i]);
        }
      } else {
        printf("\n桌上已经没有牌了。");
      }
    }
  } else {
    printf("B win\n");
    printf("B 手中的牌是：\n");
    for (i = q2.head; i <= q2.tail - 1; i++) {
      printf(" %d", q2.data[i]);
      if (s.top > 0) { //如果桌上有牌则输出桌上的牌
        printf("\n桌上的牌是");
        for (i = 1; i <= s.top; i++) {
          printf(" %d", s.data[i]);
        }
      } else {
        printf("\n桌上已经没有牌了。");
      }
    }
  }

  getchar();
  getchar();
  return 0;
}