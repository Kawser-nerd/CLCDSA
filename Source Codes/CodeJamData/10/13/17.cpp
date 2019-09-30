#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int p[1000100];
int tot,num,a1,a2,b1,b2;

bool judge(int turn,int x,int y)
{
     if (y==0 || (x-1)/y>1)   
       {
         if (turn)   return false;
         else        return true;
       }
     else
       return judge(1-turn,y,x-y);
}

void prepare()
{
     int left,right,mid;
     for (int i=2;i<=1000000;++i)
       {
         left=1;   right=i;  
         while (left<right)
           {
             mid=(left+right+1)/2;
             if (judge(0,i,mid))   left=mid;
             else   right=mid-1;
           }
         p[i]=left;
       }
}

int main()
{
    freopen("C-large.in","r",stdin);
    freopen("ou.txt","w",stdout);
    prepare();
    scanf("%d",&tot);
    num=0;
    while (tot--)
      {
        ++num;
        scanf("%d%d%d%d",&a1,&a2,&b1,&b2);
        long long ans=0;
        for (int i=a1;i<=a2;++i)
          {
            if (p[i]>=b2)   ans+=b2-b1+1;
            else
            if (p[i]>=b1)   ans+=p[i]-b1+1;
          }
        for (int i=b1;i<=b2;++i)
          {
            if (p[i]>=a2)   ans+=a2-a1+1;
            else
            if (p[i]>=a1)   ans+=p[i]-a1+1;
          }
        cout<<"Case #"<<num<<": "<<ans<<endl;
      }
}
