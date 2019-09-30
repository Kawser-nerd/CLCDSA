#include<algorithm>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<stdio.h>
#define M  100000
using namespace std;
string str[1005];
int cmp(string a,string b)
{
    return a.compare(b)<0;
}
int main()
{
    int n,len;

    while(~scanf("%d %d",&n,&len))
    {    string s = "";
        for (int i=0; i<n; i++)
            cin>>str[i];
        sort(str, str+n, cmp);
        for(int i = 0; i<n; i++)
            s+=str[i];
        cout<<s<<endl;

    }

}