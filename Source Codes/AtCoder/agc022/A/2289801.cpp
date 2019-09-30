#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    string b;
    cin>>b;
    bool a[26];
    memset(a,0,sizeof(a));
    int k=b.length();
    for(int i=0; i<k; i++)
    {
        a[b[i]-'a']=1;
    }
    int s=0;
    while(a[s]==1)
        s++;
    if(s<=k&&s!=26)
    {
        char t=s+'a';
        cout<<b<<t<<endl;
    }
    else
    {
        int p=k-1;
        for(; p>=0; p--)
        {
            a[b[p]-'a']=0;
            b[p]++;
            while(a[b[p]-'a']==1)
            {
                b[p]++;
                if(b[p]>'z')
                    break;
            }
            if(b[p]<='z')
                break;
        }
        if(p==-1)
            printf("-1\n");
        else
        {
            for(int i=0; i<k; i++)
                if(b[i]<='z')
                    printf("%c",b[i]);
                else break;
            printf("\n");
        }
    }
    return 0;
}