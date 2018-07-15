//���е���ʽ�洢�ṹʵ��,����Ϊ��ʱ��front��rear��ָ��ͷ���
#include<iostream>
#include<stdlib.h>
using namespace std;
typedef int delemtype; 
typedef struct node   //���ṹ
{
	struct node *next;
	delemtype data;
}*dlink,dnode;
typedef struct dui   //��������ṹ
{
  dlink front;
  dlink rear;
}*linkqueue,lq;
//��ʼ��һ���ն���
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
//����
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
//��ʾ����Ԫ��
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
	  cout<<"����Ϊ��"<<endl;

}
//���ӣ�ɾ����ͷԪ�ز�����Ԫ��ֵ��
linkqueue deque(linkqueue d,delemtype *e)
{
  dlink p;
  if(d->front == d->rear)
	  cout<<"����Ϊ��"<<endl;
  else
  {
	  p = d->front->next;
	  *e = p->data;
	  cout<<"�ö��ж���Ԫ��Ϊ��"<<*e<<endl;
	  d->front->next = p->next;
	  if(d->rear == p)
		  d->rear = d->front;
	  free(p);
  }
  return d;
}
//��ն���
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
  cout<<"����1Ϊ��"<<endl;
  display(d1);
  addqueue(d2,3);
  addqueue(d2,2);
  addqueue(d2,1);
  cout<<"����2Ϊ��"<<endl;
  display(d2);
  setnull(d1);
  cout<<"����1Ϊ��"<<endl;
  display(d1);
  deque(d2,&t);
  cout<<"����2Ϊ��"<<endl;
  display(d2);
  system("pause");
  return 0;
}
