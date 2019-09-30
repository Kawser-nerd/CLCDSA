#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int len;
    cin>>len;

    string s;
    cin>>s;

    int maxx=-1;
    for(int i=1;i<=len;++i)
    {
        string ll;
        string rr;
        int cnt=0;
        for(int a=0;a<i;++a)
        {
            ll+=s[a];
        }


        for(int b=i;b<len;++b)
        {
            rr+=s[b];
        }

        for(int k=0;k<26;++k)
        {
            if(ll.find('a'+k)!=-1 && rr.find('a'+k)!=-1)
            cnt++;
        }

        if(cnt>maxx)
            maxx=cnt;
    }

    cout<<maxx<<endl;

    return 0;
}