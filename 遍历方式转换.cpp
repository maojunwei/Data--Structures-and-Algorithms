#include<iostream>
#include<stdlib.h>
#include<string>
#define Max 15
using namespace std;
//��֪���������ǰ��
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

//��֪ǰ�����������
void qzh(string a,string b)
{
	int i,ll,lr;
	for(i = 0;i<b.length();i++)
		if(a[0] == b[i])
		{
			ll = i;  //��������������
			lr = b.length() - ll -1; //����������
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
//��֪ǰ�����������
void qhz(string a,string b)
{

}

int main()
{
 int wei;
//��֪��������
  string s1("ABDEFGCH"); //ǰ��
  string s2("DFEGBAHC"); //����
  string s3("FGEDBHCA"); //����

  //string s1(""); //ǰ��
  //string s2(""); //����
  //string s3(""); //����
//
  do
  { 
	cout<<"0:�˳�"<<endl;
	cout<<"1:��֪ǰ�����������"<<endl;
	cout<<"2:��֪���������ǰ��"<<endl;
	cout<<"3:��֪ǰ�����������"<<endl;
	cin>>wei;
	switch(wei)
	{
	case 0:
		break;
	case 1:
		cout<<"����Ϊ��"<<endl;
		qzh(s1,s2);
		cout<<endl;
		break;
	case 2:
		cout<<"ǰ��Ϊ��"<<endl;
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