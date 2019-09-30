#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
using namespace std;
int a[20];
int main()
{
    int n,k;
    while(~scanf("%d%d",&n,&k))
    {
        memset(a,0,sizeof(a));
        for(int i=0; i<k; i++)
        {
            int q;
            scanf("%d",&q);
            a[q]=1;
        }
        int ans=9;
        int f1=0,sum=0;
        for(int l=0;l<=9;l++){
        for(int i=0; i<=9; i++)
        {
            for(int j=0; j<=9; j++)
            {
                for(int k=0; k<=9; k++)
                {
                    for(int r=0; r<=9; r++)
                    {
                        sum=l*10000+i*1000+j*100+k*10+r;
                         int fa=0;
                          if(sum>=n)
                          {
                             ans=sum;
                              int r=0;
                              int s[20];
                              while(ans)
                              {
                                  s[r++]=ans%10;
                                  ans/=10;
                              }
                              for(int i=0;i<r;i++)
                              {
                                  if(a[s[i]]==1)
                                  {
                                      fa=1;
                                      break;
                                  }
                              }
                             if(fa==0)
                             {
                              f1=1;

                              break;
                             }
                          }
                    }
            if(f1==1) break;
                }
        if(f1==1) break;
            }
    if(f1==1)break;
    }
    if(f1==1) break;
    }
    if(f1==1)
    printf("%d\n",sum);
    else printf("0\n");
    }
}