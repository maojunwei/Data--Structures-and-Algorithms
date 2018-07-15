/*
#include<stdlib.h>
void *malloc(unsigned int size)
作用是在内存的动态存储区分配一个长度为size的连续空间。
返回的是一个指向分配域起始地址的指针，如果此函数未能成功执行（如内存不足），则返回一个空指针（NULL）
void *calloc(unsigned n,unsigned size)
作用是分配n个长度为size的连续空间。函数返回一个指向分配域起始地址的指针；如果分配不成功，返回NULL.
void free(void *p)
作用是释放由p指向的内存区，使这部分内存区能被其他变量使用
*/

//链表程序：
#include<stdlib.h>
#include<iostream>
using namespace std;
typedef int Elemtype;  //假定结点数据域数据类型为整型
typedef struct List
{
  Elemtype data;
  struct List *next;
}*link,Node;
//创建链表
link create1(int n)  //插队法实现
{
	link p;
	link head;
	int i;
	//Elemtype newdata;
	head = (link)malloc(sizeof(Node));
	head->next = NULL;
    for(i=1;i<=n;i++)  //创建n个结点
	{ 
	  Elemtype newdata;
	  p = (link)malloc(sizeof(Node));   //开辟新结点
      if(p == NULL)  //生成不成功
		  break;
	  cout<<"请输入结点数值："<<endl;
	  cin>>newdata;
	  p->data = newdata;  
	  p->next = head->next;
	  head->next = p;
	}
	return head;
}
link create2(int n)//尾插法实现
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
	cout<<"请输入结点数值："<<endl;
	cin>>p->data;
	pre = p;
  }
  p->next = NULL;
  return head;
}
//链表结点数值显示
void display(link head)
{
  link p;
  p = head;
  int i=1;
  while(p->next != NULL)
  {
	p = p->next;
	cout<<"第"<<i<<"个结点数值为"<<p->data<<endl;
	i++;
  }
}
//链表数值读取
int read(link head,int i,Elemtype *e)//读取第i个结点的数值(1,2)
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
//插入结点
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
//删除结点
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
//获取链表的长度
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
//查找结点元素X的位置
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
//连接两个链表
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

//释放链表
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
//反转链表
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
  cout<<"创建链表一"<<endl;
  head1 = create1(n1);
  cout<<"显示链表一,"<<"长度为:"<<getlen(head1)<<endl;
  display(head1);
  cout<<"创建链表二"<<endl;
  head2 = create2(n2);
  cout<<"显示链表二,"<<"长度为:"<<getlen(head2)<<endl;
  display(head2);
  cout<<"读取链表结点值"<<endl;
  if(read(head2,3,&d))
	  cout<<"链表二第三个结点数值为"<<d<<endl;
  del(head1,2);
  insert(head2,3,66);
  cout<<"链表一删除操作,"<<"长度为:"<<getlen(head1)<<endl;
  display(head1);
  cout<<"链表二插入结点,"<<"长度为:"<<getlen(head2)<<endl;
  display(head2);
  wz = locate(head2,6);
  cout<<"链表二中元素值6在第"<<wz<<"个结点"<<endl;
  cout<<"连接链表一和链表二"<<endl;
  head1 = connect(head1,head2);
  display(head1);
  cout<<"链表一连接链表二操作,"<<"长度为:"<<getlen(head1)<<endl;
  head1 = revised(head1);
  cout<<"链表反转"<<endl;
  display(head1);
  setnull(head1);
  cout<<"链表一清空操作操作,"<<"长度为:"<<getlen(head1)<<endl;
  system("pause");
  return 0;
}