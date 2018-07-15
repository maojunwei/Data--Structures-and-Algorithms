#include<iostream>
#include<stdlib.h>
#include<string>
#define Max 15
using namespace std;
//已知中序后序求前序
void zhq(string b,string c)
{
	int i,ll,lr;
	for(i = 0;i<b.length();i++)
		if(b[i] == c[c.length()-1])
		{
		  ll = i;
		  lr = b.length()  - ll - 1;
		  cout<<b[i];
		  if(ll)
		  {
		    string part1(b,0,ll),part2(c,0,ll);
			zhq(part1,part2);
		  }
		  if(lr)
		  {
		    string  part3(b,ll+1,lr),part4(c,ll,lr);
			zhq(part3,part4);
		  }
		  break;
		}

}

//已知前序中序求后序
void qzh(string a,string b)
{
	int i,ll,lr;
	for(i = 0;i<b.length();i++)
		if(a[0] == b[i])
		{
			ll = i;  //计算左子树长度
			lr = b.length() - ll -1; //右子树长度
			if(ll)
			{
				string part1(a,1,ll),part2(b,0,ll);
				qzh(part1,part2);
			}
			if(lr)
			{
				string part3(a,ll+1,lr),part4(b,ll+1,lr);
				qzh(part3,part4);
			}
			cout<<a[0];
			break;
		}

}
//已知前序后序求中序
void qhz(string a,string b)
{

}

int main()
{
 int wei;
//已知遍历序列
  string s1("ABDEFGCH"); //前序
  string s2("DFEGBAHC"); //中序
  string s3("FGEDBHCA"); //后序

  //string s1(""); //前序
  //string s2(""); //中序
  //string s3(""); //后序
//
  do
  { 
	cout<<"0:退出"<<endl;
	cout<<"1:已知前序中序求后序"<<endl;
	cout<<"2:已知中序后序求前序"<<endl;
	cout<<"3:已知前序后序求中序"<<endl;
	cin>>wei;
	switch(wei)
	{
	case 0:
		break;
	case 1:
		cout<<"后序为："<<endl;
		qzh(s1,s2);
		cout<<endl;
		break;
	case 2:
		cout<<"前序为："<<endl;
		zhq(s2,s3);
		cout<<endl;
		break;
	case 3:;
	default:;
	}
  }while(wei != 0);
  system("pause");
  return 0;
}
//int main()
//{
//  string a("hello");
//  cout<<a.length();
//  cout<<a<<endl;
//  string s(a,1,3);
//  cout<<s<<endl;
//  //cin.get();
//  //char s1[Max],s2[Max];
//  //gets(s1);
//  //gets(s2);
//  //puts(s1);
//  system("pause");
//  return 0;
//}