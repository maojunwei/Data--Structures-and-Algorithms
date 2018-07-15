//ջ����ʽ�洢�ṹ
#include<iostream>
#include<stdlib.h>
using namespace std;
typedef int selemtype;
//typedef struct stacknode *slink;
//typedef struct stacknode snode;
typedef struct stacknode   //���ṹ
{
  selemtype data;
  struct stacknode *next;
}snode,*slink;
typedef struct linkstack  //ջ������ṹ
{
	slink top;
	int count;
}*stacklink,stack;
//��ʼ��ջ,������ջ
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
//��ջ
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
//��ջ(ɾ��ջ��Ԫ�ز�������ֵ)
stacklink pop(stacklink s,selemtype *e)
{
	slink p;
	p = s->top;
	if(p == NULL)
		cout<<"ջΪ��"<<endl;
	else
	{
		*e = p->data;
		s->top = s->top->next;
		s->count--;
		free(p);
	}
	return s;
}
//��ջ�����ҷǿգ�����ջ��Ԫ��
selemtype gettop(stacklink s)
{
	if(s ->top == NULL)
		{
			cout<<"ջΪ��"<<endl;
			return -1;
	    }
	else
		return s->top->data;

}
void display(stacklink s) //��ʾջԪ��
{
	slink p;
	int n;
	
	if(s->top == NULL)
		cout<<"ջΪ��"<<endl;
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
//�ͷ�ջ
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
	 cout<<"ջ��Ԫ��Ϊ"<<m<<endl;
	 display(s1);
	 system("pause");
	 return 0;




}