#include <iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

int main()
{
   int n,i,j;
   scanf("%d",&n);
   int *box;
   box = new int[n+1];
   memset(box,0,(n+1)*sizeof(int));
   int count=0;
   for(i=0;i<n;i++)
   {
       int x;
       scanf("%d",&x);
       for(j=0;j<n;j++)
       {
           if(x<=box[j])
           {
               box[j]=x;
               break;
           }
           if(box[j]==0)
           {
               box[j]=x;
               count++;
               break;
           }
       }
   }
   delete[] box;
   cout<<count<<endl;

    return 0;
}