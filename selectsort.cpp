//�������
#include<iostream>
#include<stdio.h>
#define maxsize 10
using namespace std;
typedef struct arra
{
  int r[maxsize];
  int length;
}sqlist;
void swap(sqlist *l,int i,int j)
{
	int temp = l->r[i];
	l->r[i] = l->r[j];
	l->r[j] = temp;
}
//�������&&ѡ������
void selectsort(sqlist *l)
{
  int i,j;
  for(i=0;i<l->length;i++)
	  for(j=i;j<l->length;j++)
		  if(l->r[j] < l->r[i])
			  swap(l,i,j);
}
//��ѡ������
void selectsort0(sqlist *l)
{
  int i,j;
  int min;
  for(i=0;i<l->length;i++)
  {
	  min = i;
	  for(j=i;j<l->length;j++)
	  {
		  if(l->r[j] < l->r[min])
			  min = j;
	  }
	  if(min != i)
		  swap(l,min,i);    
  }
}
//ð�������ʼ��
void bubblesort0(sqlist *l)
{
  int i,j;
  for(i=0;i<l->length;i++)
      for(j = l->length - 1;j>i;j--)
		  if(l->r[j]<l->r[j-1])
			  swap(l,j,j-1);
  //for(i=0;i<l->length;i++)	  	  
	//  for(j = l->length - 2;j>=i;j--)//for(j = l->length - 1;j>i;j++)
		 // if(l->r[j]>l->r[j+1])
			 // swap(l,j,j+1);
}
//ð������Ľ���
void bubblesort(sqlist *l)
{
  int i,j;
  int wei = 1;
  for(i=0;i<l->length && wei;i++)
  {
     wei = 0;
	 for(j = l->length-1;j>i;j--)
		 if(l->r[j-1]>l->r[j])
		 {
		   wei = 1;
		   swap(l,j-1,j);
		 }
	 
  }
}
//��������
void insertsort(sqlist *l)
{
  int i,j,k,temp;
  for(i=1;i<l->length;i++)
  {
	  if(l->r[i]<l->r[i-1])//��Ҫ�Բ�ǿ
	  {
		 // k = i;
	      temp = l->r[i];
	      for(j = i-1;j>=0 && l->r[j] > temp;j--)
	          l->r[j+1] = l->r[j]; 		     
	      //l->r[k] = temp; 
		  l->r[j+1] = temp;
	  }
  }
}
//ϣ������
void shellsort(sqlist *l)
{
	int len,gap;
	int i,j;
	int k,temp;
	len = l->length;
	gap = len;
	do
	{
		gap = gap/3 + 1;
		for(i = gap;i<l->length;i+=gap)
		{
			if(l->r[i] < l->r[i-1])
			{
				temp = l->r[i];
				for(j = i - gap;j>=0 && l->r[j] > temp;j-=gap)
				    l->r[j+gap] = l->r[j];
				l->r[j+gap] = temp;
		    }
		}
	}
	while(gap > 1);
}
//��������
int partition(sqlist *l,int low,int high)
{
	int pv = l->r[low];
	while(low<high)
	{
	  while(low<high && l->r[high]>=pv)
		  high--;
	  swap(l,low,high);
	  while(low<high && l->r[low]<=pv)
		  low++;
	  swap(l,low,high);
	}
	return low;
}
void qsort(sqlist *l,int low,int high)
{
	if(low < high)
	{
	   int mid = partition(l,low,high);
	   qsort(l,low,mid);
	   qsort(l,mid+1,high);
	}
}
void quicksort(sqlist *l)
{
	qsort(l,0,l->length-1);
}

//������
void Heapadjust(sqlist *l,int s,int m) //�����󶥶�||������������ֵ��Ľ�������ƣ�

{
	int temp,j;
	temp = l->r[s-1];
	for(j = 2*s;j<=m;j*=2)  //�عؼ��ֽϴ�ĺ��ӽ������ɸѡ
	{
	  if(j<m && l->r[j-1] < l->r[j])
		  j++; //��j�����
	  if(temp >= l->r[j-1])
		  break;
	  l->r[s-1] = l->r[j-1];
	  
	  
	  s = j;
	}
	l->r[s-1] = temp;
}
void Heapsort(sqlist *l)
{
	int i;
	for(i = (l->length )/2;i>0;i--)  //���������й���Ϊ�󶥶�(�����)
		Heapadjust(l,i,l->length);
	for(i = l->length;i>1;i--)  //���ڵ���ĩβԪ�ؽ�������������
	{
	    swap(l,0,i-1);
		Heapadjust(l,1,i-1);
	}
}

//�鲢����
//void Merge(sqlist *l1,sqlist *l2,int low,int mid,int high)
//{
//	int i = low; 
//	int j = mid+1;
//	int k = low;//
//	while(i<=mid && j<=high)
//	{
//		if(l1->r[i]<l1->r[j])
//			l2->r[k++] = l1->r[i++];
//		else
//			l2->r[k++] = l1->r[j++];
//	}
//	while(i<=mid)
//		l2->r[k++] = l1->r[i++];
//	while(j<=high)
//		l2->r[k++] = l1->r[j++];       
//}
//void Msort(sqlist *l1,sqlist *l2,int low,int high)
//{
//  if(low == high)
//	  l2->r[low] = l1->r[low];
//  else
//  {
//     sqlist *l = (sqlist*)(malloc(sizeof(sqlist)));//������ʽ�� int *space = (int*)malloc(sizeof(int) * len)
//	 int mid = (low+high)/2;
//	 if(l != NULL)
//	 {
//	   Msort(l1,l,low,mid);
//	   Msort(l1,l,mid+1,high);
//	   Merge(l,l2,low,mid,high);
//	 }  
//	 free(l);
//  }
//}
//
//void Mergesort(sqlist *l)
//{
//	Msort(l,l,0,l->length-1);
//}
 void Merge(int s1[],int s2[],int low,int mid,int high)
 {
	 int i = low; 
	 int j = mid+1;
	 int k = low;//
	 while(i<=mid && j<=high)
	 {
		 if(s1[i] < s1[j])
			 s2[k++] = s1[i++];
		 else
			 s2[k++] = s1[j++];
	 }
	 while(i<=mid)
		 s2[k++] = s1[i++];
	 while(j<=high)
		 s2[k++] = s1[j++];       
 }
 void Msort(int s1[],int s2[],int low,int high)
 {
   if(low == high)
	   s2[low] = s1[low];
   else
   {
      //sqlist *l = (sqlist*)(malloc(sizeof(sqlist)));//������ʽ�� int *space = (int*)malloc(sizeof(int) * len)
	  int s[maxsize];
	  int mid = (low+high)/2;
	
	    Msort(s1,s,low,mid);
	    Msort(s1,s,mid+1,high);
	    Merge(s,s2,low,mid,high);
	
   }
 }
 void Mergesort(sqlist *l)
 {
	 Msort(l->r,l->r,0,l->length-1);
 }

int main()
{
	sqlist L = {{9,1,5,8,3,7,4,6,2,3},10};//
	sqlist *l;
	l = &L;
	//int len = sizeof(l->r)/sizeof(*(l->r)); a�����С
	cout<<"��ʼ���У�"<<endl;
	for(int i = 0;i < l->length;i++)	
	   cout<<l->r[i]<<" ";
	cout<<endl;
	//�������
	//selectsort(l);
	//selectsort0(l);
	//bubblesort0(l);
	 //bubblesort(l);
	//insertsort(l);
	//shellsort(l);
	//quicksort(l);
	//Mergesort(l);
	Heapsort(l);
	cout<<"���������У�"<<endl;
	for(int i = 0;i < l->length;i++)	
	   cout<<l->r[i]<<" ";
	cout<<endl;
	system("pause");
	return 0;	   
}