#include <stdio.h>
#include <stdlib.h>
struct node {
  int data;
  struct node *next;
};

int main() {
  struct node *head, *p, *q, *t;
  int i, n, a;
  scanf("%d ", &n);
  head = NULL;             //头指针初始为空
  for (i = 1; i <= n; i++) //读入10个数
  {
    scanf("%d", &a);
    //动态申请一个空间，用来存放一个结点,并用临时指针p指向这个结点
    p = (struct node *)malloc(sizeof(struct node));
    p->data = a; //将数据存储到当前结点
    p->next = NULL;
    if (head == NULL) {
      head = p; //如果是第一个节点，则将头指针指向这个结点
    } else {
      q->next = p; //如果不是第一个创建的节点，则将上一个的后继指向这个节点
    }
    q = p; //指针q也指向当前节点

    //输出链表中的所有数
    t = head;
    while (t != NULL) {
      printf("%d ", t->data);
      t = t->next;
    }
    getchar();
    getchar();
    return 0;
  }