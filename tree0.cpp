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

//初始化二叉树，添加根节点
Ctree inittree()
{
 Ctree tnode;
 if(tnode = Ctree(malloc(sizeof(cttype))))
 {
   cout<<"请输入一个根节点数据"<<endl;
   cin>>tnode->data;
   tnode->left = NULL;
   tnode->right = NULL;
   return tnode;
 }
 return NULL;
}
//查找结点
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
//添加结点
void addtreenode(Ctree tree)
{
	Ctree pnode,parent;
	telemtype data;
	int xz;

	if(pnode = Ctree(malloc(sizeof(cttype))))
	{
	  cout<<"请输入结点数据"<<endl;
	  cin>>pnode->data;
	  pnode->left = NULL;
	  pnode->right = NULL;
	  
	  cout<<"输入该结点父结点数据："<<endl;
	  cin>>data;
	  parent = treefindnode(tree,data);
	  if(!parent)
	  {
	    cout<<"未找到其父结点"<<endl;
		free(pnode);
		return;
	   }
	  do
	  {
		  cout<<"1.添加该结点到左子树"<<endl;
		  cout<<"2.添加该结点到右子树"<<endl;
		  cin>>xz;
		  if(xz == 1 || xz == 2)
		  {
			if (parent == NULL)
			{
			  cout<<"不存在父结点，请先设置父结点"<<endl;
			}
			else
			{
			  switch(xz)
			  {
				  case 1:
					  if(parent->left)
						  cout<<"左子树不为空"<<endl;
					  else
						  parent->left = pnode;
					  break;
				  case 2:
					  if(parent->right)
						  cout<<"右子树不为空"<<endl;
					  else
						  parent->right = pnode;
					  break;
				  default:
					  cout<<"无效参数"<<endl;
				}
			 }
		   }
	  }while(xz != 1 && xz != 2);
	}
}
//获取左子树
Ctree getleft(Ctree treenode)
{
  if(treenode)
	  return treenode->left;
  else
	  return NULL;
}
//获取右子树
Ctree getright(Ctree treenode)
{
   if(treenode)
	   return treenode->right;
   else
	   return NULL;
}
//判断空树
int Treeisempty(Ctree treenode)
{
   if(treenode)
	   return 1;
   else
	   return 0;
}
//计算树的深度
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
//清空二叉树
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
//显示显示当前结点数据
void treenodedata(Ctree treenode)
{
	if(treenode)
		cout<<treenode->data;
	else
		cout<<"树为空"<<endl;
}
//按层遍历
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
//先序遍历算法
  void dlrtree(Ctree treenode,void(*treenodedata)(Ctree p))
  {
	  if(treenode)
	  {
	    treenodedata(treenode);
		dlrtree(treenode->left,treenodedata);
		dlrtree(treenode->right,treenodedata);
	  }
    
  }
//非递归实现前序遍历
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


//中序遍历
  void ldrtree(Ctree treenode,void(*treenodedata)(Ctree p))
  {
	if(treenode)
	{
		ldrtree(treenode->left,treenodedata);
		treenodedata(treenode);
		ldrtree(treenode->right,treenodedata);
	
	}
  }
//非递归实现中序遍历
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
//后序遍历
  void lrdtree(Ctree treenode,void(*treenodedata)(Ctree p))
  {
    if(treenode)
	{
		lrdtree(treenode->left,treenodedata);
		lrdtree(treenode->right,treenodedata);
		treenodedata(treenode);
	}
  }
  //非递归实现后序遍历
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
//树操作示例
int main()
  {
	Ctree root = NULL;
	int men;
	void (*treenodedatal)(Ctree p);
	treenodedatal = treenodedata;
	root = inittree();
	do
	{
		cout<<"菜单"<<endl;
		cout<<"0:退出"<<endl;
		cout<<"1:添加二叉树结点"<<endl;
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
//遍历
	do
	{
	 cout<<"遍历二叉树："<<endl;
	 cout<<"1:先序遍历"<<endl;
	 cout<<"2:中序遍历"<<endl;
	 cout<<"3:后序遍历"<<endl;
	 cout<<"4:按层遍历"<<endl;
	 cin>>men;
	 switch(men)
	 {
	 case 1:
		 cout<<"先序遍历结果：";
		 //dlrtree(root,treenodedatal);
		 dlrtree1(root);
		 cout<<endl;
		 break;
	 case 2:
		 cout<<"中序遍历结果：";
		 //ldrtree(root,treenodedatal);
		 ldrtree1(root);
		 cout<<endl;
		 break;
	 case 3:
		 cout<<"后序遍历结果：";
		 //lrdtree(root,treenodedatal);
		 lrdtree1(root);
		 cout<<endl;
		 break;
	 case 4:
		 cout<<"按层遍历结果：";
		 leveltree(root,treenodedatal);
		 cout<<endl;
		 break;
	 default:
		 break;
	 }
	}while(men != 0);
	//树的深度
	cout<<"二叉树深度为："<<treedepth(root)<<endl;
	Cleartree(root);
	root = NULL;
	system("pause");
	return 0;
  }
