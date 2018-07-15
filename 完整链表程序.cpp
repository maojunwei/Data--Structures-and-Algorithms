/*
#include<stdlib.h>
void *malloc(unsigned int size)
���������ڴ�Ķ�̬�洢������һ������Ϊsize�������ռ䡣
���ص���һ��ָ���������ʼ��ַ��ָ�룬����˺���δ�ܳɹ�ִ�У����ڴ治�㣩���򷵻�һ����ָ�루NULL��
void *calloc(unsigned n,unsigned size)
�����Ƿ���n������Ϊsize�������ռ䡣��������һ��ָ���������ʼ��ַ��ָ�룻������䲻�ɹ�������NULL.
�������ͷ���pָ����ڴ�����ʹ�ⲿ���ڴ����ܱ���������ʹ��
*/

//�������
#include<stdlib.h>
#include<iostream>
using namespace std;
typedef int Elemtype;  //�ٶ������������������Ϊ����
typedef struct List
{
  Elemtype data;
  struct List *next;
}*link,Node;
//��������
link create1(int n)  //��ӷ�ʵ��
{
	link p;
	link head;
	int i;
	//Elemtype newdata;
	head = (link)malloc(sizeof(Node));
	head->next = NULL;
    for(i=1;i<=n;i++)  //����n�����
	{ 
	  Elemtype newdata;
	  p = (link)malloc(sizeof(Node));   //�����½��
      if(p == NULL)  //���ɲ��ɹ�
		  break;
	  cout<<"����������ֵ��"<<endl;
	  cin>>newdata;
	  p->data = newdata;  
	  p->next = head->next;
	  head->next = p;
	}
	return head;
}
link create2(int n)//β�巨ʵ��
{
  link head;
  link p,pre;
  int i;
  head = (link)malloc(sizeof(Node));
  pre = head;
  for(i=1;i<=n;i++)
  {
    p = (link)malloc(sizeof(Node));
	pre->next = p;
	cout<<"����������ֵ��"<<endl;
	cin>>p->data;
	pre = p;
  }
  p->next = NULL;
  return head;
}
//��������ֵ��ʾ
void display(link head)
{
  link p;
  p = head;
  int i=1;
  while(p->next != NULL)
  {
	p = p->next;
	cout<<"��"<<i<<"�������ֵΪ"<<p->data<<endl;
	i++;
  }
}
//������ֵ��ȡ
int read(link head,int i,Elemtype *e)//��ȡ��i��������ֵ(1,2)
{
  link p;
  p = head->next;
  int j=1;
  while(p && j<i)
  {
   p = p->next;
   j++;
  }
  if(!p && j > i)
  {
    return 0;
  }
	*e = p->data;
	return 1;
}
//������
link insert(link head,int i,Elemtype e)
{
  link p,pre;
  p = head;
  int j=1;
  pre = (link)malloc(sizeof(Node));
  pre->data = e;
  while(j<i)
  {
	  p = p->next;
	  j++;
  }
  pre->next = p->next;
  p->next = pre;
  return head;
}
//ɾ�����
link del(link head,int i)
{
  link p,pre;
  p = head;
  int j = 1;
  while(j<i)
  {
	  p = p->next;
	  j++;
  }
  pre = p->next;
  p->next = pre->next;
  free(pre);
  return head;
 }
//��ȡ����ĳ���
int getlen(link head)
{
  link p;
  p = head;
  int i=0;
  while(p->next != NULL)
  {
	  p = p->next;
	  i++;
  }
  return i;
}
//���ҽ��Ԫ��X��λ��
int locate(link head,Elemtype a)
{
  link p;
  p = head->next;
  int i = 0;
  while(p != NULL && p->data != a)
  {
	  p = p->next;
	  i++;
  }
  if(p = NULL)
	  return 0;
  else
	  return i+1;
}
//������������
link connect(link head1,link head2)
{
  link p;
  p = head1;
  while(p->next != NULL)
  {
	  p = p->next;
  }
  p->next = head2->next;
  return head1;
}

//�ͷ�����
link setnull(link head)
{
  link p,q;
  p = head->next;
  while(p != NULL)
  {   
	  q = p->next;
	  free(p);
	  p = q; 
  }
  head->next = NULL;
  return head;
}
//��ת����
link revised(link head)
{
  link node;
  link pre;
  link latter;
  if(head->next == NULL)
	  return head;
  node = head->next;
  pre = NULL;
  while(node != NULL)
  {
	  latter = node->next;
	  if(latter == NULL)
	     head ->next = node;
	  node ->next = pre;
	  pre = node;
	  node = latter;
  }
return head;
}
int main()
{
  link head1;
  link head2;
  int n1 = 3;
  int n2 = 5;
  Elemtype d;
  int wz;
  cout<<"��������һ"<<endl;
  head1 = create1(n1);
  cout<<"��ʾ����һ,"<<"����Ϊ:"<<getlen(head1)<<endl;
  display(head1);
  cout<<"���������"<<endl;
  head2 = create2(n2);
  cout<<"��ʾ�����,"<<"����Ϊ:"<<getlen(head2)<<endl;
  display(head2);
  cout<<"��ȡ������ֵ"<<endl;
  if(read(head2,3,&d))
	  cout<<"����������������ֵΪ"<<d<<endl;
  del(head1,2);
  insert(head2,3,66);
  cout<<"����һɾ������,"<<"����Ϊ:"<<getlen(head1)<<endl;
  display(head1);
  cout<<"�����������,"<<"����Ϊ:"<<getlen(head2)<<endl;
  display(head2);
  wz = locate(head2,6);
  cout<<"�������Ԫ��ֵ6�ڵ�"<<wz<<"�����"<<endl;
  cout<<"��������һ�������"<<endl;
  head1 = connect(head1,head2);
  display(head1);
  cout<<"����һ�������������,"<<"����Ϊ:"<<getlen(head1)<<endl;
  head1 = revised(head1);
  cout<<"����ת"<<endl;
  display(head1);
  setnull(head1);
  cout<<"����һ��ղ�������,"<<"����Ϊ:"<<getlen(head1)<<endl;
  system("pause");
  return 0;
}