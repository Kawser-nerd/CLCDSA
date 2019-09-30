#include<iostream>
#include<cstdio>
#include<cstring>
#include<stdio.h>
#include<algorithm>
#include<algorithm>
#define L long long
#include<string.h>
#include <math.h>
long long  array1[100002];
using namespace std;
int n;
long long a,b;
int judge(int x)
{
    long long sum=0;
      for(int i=0;i<n;i++)
      {
          long long num=array1[i]-x*b;
          if(num>0)
          {
              sum+= ceil((num*1.0)/(a-b));
              if(sum>x||sum<0)
                return 0;
          }
      }
      return 1;
}

int main()
{   int i;
    while(cin>>n>>a>>b)
    {
        for(i=0;i<n;i++)
        {
        cin>>array1[i];
        }
            sort(array1,array1+n);
        long long l=0,r=array1[n-1];
         while(l<r)
         {
             long long mind=(l+r)>>1;
             if(judge(mind)==1)  r=mind;
             else
                 l=mind+1;
         }
         cout<<r<<endl;
    }

       return 0;
}