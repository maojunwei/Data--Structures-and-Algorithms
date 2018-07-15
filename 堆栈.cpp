//栈的链式存储结构
#include<iostream>
#include<stdlib.h>
using namespace std;
typedef int selemtype;
//typedef struct stacknode *slink;
//typedef struct stacknode snode;
typedef struct stacknode   //结点结构
{
  selemtype data;
  struct stacknode *next;
}snode,*slink;
typedef struct linkstack  //栈的链表结构
{
	slink top;
	int count;
}*stacklink,stack;
//初始化栈,建立空栈
stacklink init()
{
   //slink p;
   //p = NULL;
   stacklink s = (stacklink)malloc(sizeof(stack));
   s->top = NULL;
   s->count = 0;
   return s;
}
int empty(stacklink s)
{
  if(s->top == NULL)
	  return 1;
  else
	  return 0;
}
//入栈
stacklink push(stacklink s,selemtype e)
{
   slink p;
   p = (slink)malloc(sizeof(snode));
   p->data = e;
   p->next = s->top;
   s->top = p;
   s->count++;
   return s;
}
//出栈(删除栈顶元素并返回其值)
stacklink pop(stacklink s,selemtype *e)
{
	slink p;
	p = s->top;
	if(p == NULL)
		cout<<"栈为空"<<endl;
	else
	{
		*e = p->data;
		s->top = s->top->next;
		s->count--;
		free(p);
	}
	return s;
}
//若栈存在且非空，返回栈顶元素
selemtype gettop(stacklink s)
{
	if(s ->top == NULL)
		{
			cout<<"栈为空"<<endl;
			return -1;
	    }
	else
		return s->top->data;

}
void display(stacklink s) //显示栈元素
{
	slink p;
	int n;
	
	if(s->top == NULL)
		cout<<"栈为空"<<endl;
	else
		{
			p = s->top;
			n = s->count;
			for(int i=1;i<=n;i++)
			{

				cout <<p->data<<endl;
				p = p->next;
			}
	}
		
}
//释放栈
stacklink setnull(stacklink s)
{
	slink p,later;
	p = s->top;
	while(p!=NULL)
	{
		later = p->next;
		free(p);
		p = later;
	}
	return s;
}
int main()
{
	 selemtype m;
     stacklink s1 = init();
	 stacklink s2 = init();
	 push(s1,1);
	 push(s1,2);
	 push(s1,3);
	 display(s1);
	 push(s2,3);
	 push(s2,2);
	 push(s2,1);
	 display(s2);
	 cout<<gettop(s1)<<endl;
	 cout<<gettop(s2)<<endl;
	 s1 = pop(s1,&m);
	 cout<<"栈顶元素为"<<m<<endl;
	 display(s1);
	 system("pause");
	 return 0;




}