#include<iostream>
#include<string>
#include<cstring>
using namespace std;
string s;
int a[1005],frontr;
int main()
{
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='B')
        {
            if(frontr!=0)
                frontr--;
        }
        else
            a[frontr++]=s[i]-'0';
    }
    for(int i=0;i<frontr;i++)
        printf("%d",a[i]);
    printf("\n");
    return 0;
}