#include <stdio.h>
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <cstdio>
#include <stack>
#include <vector>
#include <map>

#include <string.h>
#define inf 0x7fffffff
using namespace std;
//1232
int a,b,c,k,n,m,l[5200][5010],j[100010],o[100200],i,d,dx[10]={0,1,0,-1},dy[10]={1,0,-1,0};
long long x,y,z;
stack<int> s;
struct P
{
    int x;
    int y;
    bool operator<(const P &a)const
    {
        return y>a.y;
    }
};

 map<int, int> p;
queue<P> q;
priority_queue<int> q1;
string r,r1[110];
//char r[2000000],r1[5000000];
vector<P> v[5010];

bool sdf(int a,int b)
{
    if(l[a]!=l[b])
    return l[a]<l[b];
        else
        return l[a+c]<l[b+c];
}

//alohomora
int main()
{
    scanf("%d",&a);
    k=1;
    for(;(k*k+k)/2<a;k++);

    printf("%d",k);
    return 0;
}