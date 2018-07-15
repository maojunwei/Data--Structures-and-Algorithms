//队列的链式存储结构实现,队列为空时，front和rear都指向头结点
#include<iostream>
#include<stdlib.h>
using namespace std;
typedef int delemtype; 
typedef struct node   //结点结构
{
	struct node *next;
	delemtype data;
}*dlink,dnode;
typedef struct dui   //队列链表结构
{
  dlink front;
  dlink rear;
}*linkqueue,lq;
//初始化一个空队列
linkqueue init()
{
   linkqueue d;
   dlink p;
   d = (linkqueue)malloc(sizeof(lq));
   p = (dlink)malloc(sizeof(dnode));
   d->front = p;
   d->rear = p;
   return d;
}
//入列
linkqueue addqueue(linkqueue d,delemtype e)
{
  dlink p;
  p = (dlink)malloc(sizeof(dnode));
  p ->data = e;
  p->next = NULL;
  d->rear->next = p;
  d->rear = p;
  return d;
}
//显示队列元素
void display(linkqueue d)
{
  dlink p;
  if(d->front!=d->rear)
  {
	  p = d->front->next;
	  do
	  {

		  cout<<p->data<<endl;
		  p = p->next;
	  }
	  while(p!=NULL);
  }
  else
	  cout<<"队列为空"<<endl;

}
//出队（删除队头元素并返回元素值）
linkqueue deque(linkqueue d,delemtype *e)
{
  dlink p;
  if(d->front == d->rear)
	  cout<<"队列为空"<<endl;
  else
  {
	  p = d->front->next;
	  *e = p->data;
	  cout<<"该队列队首元素为："<<*e<<endl;
	  d->front->next = p->next;
	  if(d->rear == p)
		  d->rear = d->front;
	  free(p);
  }
  return d;
}
//清空队列
linkqueue setnull(linkqueue d)
{
  dlink p,later;
  p = d->front;  
  if(d->front != d->rear)
  {   
	  p = p->next;
	  do
	  {
		  later = p->next;
		  free(p);
		  p = later;
	  }
	  while(p!=NULL);
	  d->rear = d->front;
   }
  return d;
}
int main()
{
  delemtype t;
  linkqueue d1 = init();
  linkqueue d2 = init();
  addqueue(d1,1);
  addqueue(d1,2);
  addqueue(d1,3);
  cout<<"队列1为："<<endl;
  display(d1);
  addqueue(d2,3);
  addqueue(d2,2);
  addqueue(d2,1);
  cout<<"队列2为："<<endl;
  display(d2);
  setnull(d1);
  cout<<"队列1为："<<endl;
  display(d1);
  deque(d2,&t);
  cout<<"队列2为："<<endl;
  display(d2);
  system("pause");
  return 0;
}
