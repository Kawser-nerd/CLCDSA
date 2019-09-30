#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string s;
    char s1[10000];
    while(cin>>s)
    {
        int len=s.size();
        int j=0;
        for(int i=0;i<len;i++)
        {
            if(s[i]!='B')
                s1[j++]=s[i];
            else
            {
                j--;
                if(j<0)
                    j=0;
            }
        }
        s1[j]='\0';
        cout<<s1<<endl;
    }
    return 0;
}