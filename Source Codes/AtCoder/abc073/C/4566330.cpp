#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#define maxn 1005
using namespace std;
typedef long long  LL;
map<string,int>mp;
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        string s;
        cin>>s;
        mp[s]++;
    }
        map<string,int>::iterator it;
        int sum=0;
        for(it=mp.begin();it!=mp.end();++it)
        {
            int t=it->second;
            if(t%2==1)
                sum++;
        }
        cout<<sum<<endl;

}