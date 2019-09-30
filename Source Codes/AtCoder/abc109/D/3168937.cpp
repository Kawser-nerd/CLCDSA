#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct node
{
    int a,b,c,d;
}re[10000];
int a[1005][1005];
int main()
{
    int h,w;
    scanf("%d%d",&h,&w);
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++)
        cin>>a[i][j];
    int cnt=0;
    for(int i=1;i<h;i++)
        for(int j=1;j<=w;j++)
        if(a[i][j]%2==1) a[i][j]--,a[i+1][j]++,re[cnt].a=i,re[cnt].b=j,re[cnt].c=i+1,re[cnt].d=j,cnt++;
    for(int j=1;j<w;j++)
        if(a[h][j]%2==1) a[h][j]--,a[h][j+1]++,re[cnt].a=h,re[cnt].b=j,re[cnt].c=h,re[cnt].d=j+1,cnt++;
    printf("%d\n",cnt);
    for(int i=0;i<cnt;i++)
        printf("%d %d %d %d\n",re[i].a,re[i].b,re[i].c,re[i].d);
}