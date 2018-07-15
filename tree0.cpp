#include<iostream>
#include<stdlib.h>
#include<stack>
#define Tlen 20
using namespace std;
typedef char telemtype;
typedef struct chaintree
{
  telemtype data;
  struct chaintree *left;
  struct chaintree *right;
} cttype,*Ctree;

//��ʼ������������Ӹ��ڵ�
Ctree inittree()
{
 Ctree tnode;
 if(tnode = Ctree(malloc(sizeof(cttype))))
 {
   cout<<"������һ�����ڵ�����"<<endl;
   cin>>tnode->data;
   tnode->left = NULL;
   tnode->right = NULL;
   return tnode;
 }
 return NULL;
}
//���ҽ��
Ctree treefindnode(Ctree treenode,telemtype td)
{
  Ctree ptr;
  if(treenode == NULL)
	  return NULL;
  else
  {
	if(treenode->data == td)
		return treenode;
	else
	{
		if(ptr = treefindnode(treenode->left,td))
			return ptr;
		else if(ptr = treefindnode(treenode->right,td))
			return ptr;
		else
			return NULL;
	 }
   }
}
//��ӽ��
void addtreenode(Ctree tree)
{
	Ctree pnode,parent;
	telemtype data;
	int xz;

	if(pnode = Ctree(malloc(sizeof(cttype))))
	{
	  cout<<"������������"<<endl;
	  cin>>pnode->data;
	  pnode->left = NULL;
	  pnode->right = NULL;
	  
	  cout<<"����ý�㸸������ݣ�"<<endl;
	  cin>>data;
	  parent = treefindnode(tree,data);
	  if(!parent)
	  {
	    cout<<"δ�ҵ��丸���"<<endl;
		free(pnode);
		return;
	   }
	  do
	  {
		  cout<<"1.��Ӹý�㵽������"<<endl;
		  cout<<"2.��Ӹý�㵽������"<<endl;
		  cin>>xz;
		  if(xz == 1 || xz == 2)
		  {
			if (parent == NULL)
			{
			  cout<<"�����ڸ���㣬�������ø����"<<endl;
			}
			else
			{
			  switch(xz)
			  {
				  case 1:
					  if(parent->left)
						  cout<<"��������Ϊ��"<<endl;
					  else
						  parent->left = pnode;
					  break;
				  case 2:
					  if(parent->right)
						  cout<<"��������Ϊ��"<<endl;
					  else
						  parent->right = pnode;
					  break;
				  default:
					  cout<<"��Ч����"<<endl;
				}
			 }
		   }
	  }while(xz != 1 && xz != 2);
	}
}
//��ȡ������
Ctree getleft(Ctree treenode)
{
  if(treenode)
	  return treenode->left;
  else
	  return NULL;
}
//��ȡ������
Ctree getright(Ctree treenode)
{
   if(treenode)
	   return treenode->right;
   else
	   return NULL;
}
//�жϿ���
int Treeisempty(Ctree treenode)
{
   if(treenode)
	   return 1;
   else
	   return 0;
}
//�����������
int treedepth(Ctree treenode)
{
  int depleft,depright;
  if(treenode == NULL)
	  return 0;
  else
  {
	  depleft = treedepth(treenode->left);
	  depright = treedepth(treenode->right);
	  if(depleft > depright)
		  return depleft+1;
	  else
		  return depright+1;
   }
}
//��ն�����
void Cleartree(Ctree treenode)
{
  if(treenode)
  {
	  Cleartree(treenode->left);
	  Cleartree(treenode->right);
	  free(treenode);
	  //treenode = NULL;
  }
}
//��ʾ��ʾ��ǰ�������
void treenodedata(Ctree treenode)
{
	if(treenode)
		cout<<treenode->data;
	else
		cout<<"��Ϊ��"<<endl;
}
//�������
void leveltree(Ctree treenode,void(*treenodedata)(Ctree p))
{
  Ctree p;
  Ctree q[Tlen];
  int head = 0,tail = 0;
  if(treenode)
  {
	tail = (tail+1)%Tlen;
	q[tail] = treenode;
  }
  while(head != tail)
  {
	  head = (head +1)%Tlen;
	  p = q[head];
	  treenodedata(p); //cout<<p->data<<endl;
	  if(p->left != NULL)
	  {
	    tail = (tail + 1)%Tlen;
		q[tail] = p->left;
	  }
	  if(p->right != NULL)
	  {
	    tail = (tail+1)%Tlen;
		q[tail] = p->right;
	  }
  }
}
//��������㷨
  void dlrtree(Ctree treenode,void(*treenodedata)(Ctree p))
  {
	  if(treenode)
	  {
	    treenodedata(treenode);
		dlrtree(treenode->left,treenodedata);
		dlrtree(treenode->right,treenodedata);
	  }
    
  }
//�ǵݹ�ʵ��ǰ�����
  void dlrtree1(Ctree treenode)
  {
	  std::stack<Ctree> s;
	  Ctree p = treenode;
	  while(p!= NULL || !s.empty())
	  {
		while(p != NULL)
		{
			cout<<p->data;
			s.push(p);
			p = p->left;		
		}
		while(!s.empty())
		{
			p = s.top();
			s.pop();
			p = p->right;		
		}  
	  }
  
  }


//�������
  void ldrtree(Ctree treenode,void(*treenodedata)(Ctree p))
  {
	if(treenode)
	{
		ldrtree(treenode->left,treenodedata);
		treenodedata(treenode);
		ldrtree(treenode->right,treenodedata);
	
	}
  }
//�ǵݹ�ʵ���������
  void ldrtree1(Ctree treenode)
  {
	  std::stack<Ctree> s;
	  Ctree p = treenode;
	  while(p != NULL || !s.empty())
	  {
		while(p!= NULL)
		{
		   s.push(p);
		   p = p->left;
		}
		while(!s.empty())
		{
			p = s.top();
			cout<<p->data;
			s.pop();
			p = p->right;		
		}
	  }  
  }
//�������
  void lrdtree(Ctree treenode,void(*treenodedata)(Ctree p))
  {
    if(treenode)
	{
		lrdtree(treenode->left,treenodedata);
		lrdtree(treenode->right,treenodedata);
		treenodedata(treenode);
	}
  }
  //�ǵݹ�ʵ�ֺ������
  void lrdtree1(Ctree treenode)
  {
	  std::stack<Ctree> s;
	  Ctree p;
	  Ctree pre = NULL;
	  s.push(treenode);
	  while(!s.empty())
	  {
		  p = s.top();
		  if((p->left == NULL && p->right == NULL) || (pre!=NULL && (pre == p->left || pre == p->right)))
		  {
			  cout<<p->data;
			  s.pop();
			  pre = p;
		  }
		  else
		  {
			  if(p->right)
				  s.push(p->right);
			  if(p->left)
				  s.push(p->left);
		  }  
	  }  
  }
//������ʾ��
int main()
  {
	Ctree root = NULL;
	int men;
	void (*treenodedatal)(Ctree p);
	treenodedatal = treenodedata;
	root = inittree();
	do
	{
		cout<<"�˵�"<<endl;
		cout<<"0:�˳�"<<endl;
		cout<<"1:��Ӷ��������"<<endl;
		cin>>men;
		switch(men)
		{
		case 1:
			addtreenode(root);
			break;
		case 0:
			break;
		default:;
		}
	}while(men != 0);
//����
	do
	{
	 cout<<"������������"<<endl;
	 cout<<"1:�������"<<endl;
	 cout<<"2:�������"<<endl;
	 cout<<"3:�������"<<endl;
	 cout<<"4:�������"<<endl;
	 cin>>men;
	 switch(men)
	 {
	 case 1:
		 cout<<"������������";
		 //dlrtree(root,treenodedatal);
		 dlrtree1(root);
		 cout<<endl;
		 break;
	 case 2:
		 cout<<"������������";
		 //ldrtree(root,treenodedatal);
		 ldrtree1(root);
		 cout<<endl;
		 break;
	 case 3:
		 cout<<"������������";
		 //lrdtree(root,treenodedatal);
		 lrdtree1(root);
		 cout<<endl;
		 break;
	 case 4:
		 cout<<"������������";
		 leveltree(root,treenodedatal);
		 cout<<endl;
		 break;
	 default:
		 break;
	 }
	}while(men != 0);
	//�������
	cout<<"���������Ϊ��"<<treedepth(root)<<endl;
	Cleartree(root);
	root = NULL;
	system("pause");
	return 0;
  }
