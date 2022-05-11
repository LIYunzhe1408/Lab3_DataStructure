//
// Created by 刘沛根 on 2022/5/11.
//
#include<bits/stdc++.h>
using namespace std;
int searchmid1(const int *num1,const int *num2,int n) //第一种查找中位数，算法时间复杂度为O(n)
{
    int *num;
    num=new int[2*n];
    int k=0,i,j;
    for(i=0,j=0;i<n,j<n;)  //将两个有序数组依次比较各元素，并有序插入新数组，即合并
    {
        if(num1[i]<num2[j])
        {
            num[k]=num1[i];
            k++;
            i++;
        }
        else if(num1[i]>num2[j])
        {
            num[k]=num2[j];
            k++;
            j++;
        }
        else
        {
            num[k]=num1[i];
            num[k+1]=num2[j];
            i++;
            j++;
            k=k+2;
        }
    }
    if(i==n&&j<n)  //判断是否有数组的元素没遍历完，没遍历完的元素都依次加入新数组
    {
        for(;j<n;j++)
        {
            num[k]=num2[j];
            k++;
        }
    }
    else if(j==n&&i<n)
    {
        for(;i<n;i++)
        {
            num[k]=num1[i];
            k++;
        }
    }
    return num[n-1];  //返回合并后的有序数组的中位数
}
int searchmid2(int *num1,int *num2,int n)  //第二种求中位数，采用折半查找，算法时间复杂度为O(logn)
{
    int mid1,mid2;
    int l1=0,r1=n-1,l2=0,r2=n-1;
    while(l1!=r1||l2!=r2)
    {
        mid1=(l1+r1)/2;
        mid2=(l2+r2)/2;
        if(num1[mid1]==num2[mid2])  //比较两个数组区间的中位数
        {
            return num1[mid1];
        }
        else if(num1[mid1]<num2[mid2])
        {
            if((l1+r1)%2==0)  //判断是奇数还是偶数
            {
                l1=mid1;
                r2=mid2;
            }
            else
            {
                l1=mid1+1;
                r2=mid2;
            }
        }
        else
        {
            if((l1+r1)%2==0)
            {
                r1=mid1;
                l2=mid2;
            }
            else
            {
                r1=mid1;
                l2=mid2+1;
            }
        }
    }
    return num1[r1]<num2[r2]?num1[r1]:num2[r2];  //返回
}
int main() {

    int n;
    cin>>n;
    int *num1=new int[n];
    int *num2=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>num1[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>num2[i];
    }
    cout<<searchmid2(num1,num2,n)<<endl;
    cout<<searchmid1(num1,num2,n)<<endl;

    return 0;
}


