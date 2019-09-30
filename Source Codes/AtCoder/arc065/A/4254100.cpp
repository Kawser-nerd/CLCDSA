#include <iostream>
using namespace std;
#include <algorithm>
#include <string>
#include <vector>
#define ll long long
struct s
{
    int timu;
    int time;
};
int main()
{

    string s1,s2,s3,s4,s5;
    cin>>s1;
    s2="dream";
    s3="dreamer";
    s4="erase";
    s5="eraser";
    int flag=1;
    int p1,p2,p3,p4;
    int f1,f2,f3,f4;
    ll l;
    while(1)
    {
        flag=0;
        f1=0;f2=0;f3=0;f4=0;
        l=s1.length();
        p1=l-5;
        for(int i=0;i<5;i++)
        {
            if(s1[p1+i]!=s2[i])
            {
                f1=1;
            }
        }
        if(f1==0)
        {
            s1.erase(p1,5);flag=1;
        }

        l=s1.length();
        p2=l-7;
        for(int i=0;i<7;i++)
        {
            if(s1[p2+i]!=s3[i])
            {
                f2=1;
            }
        }
        if(f2==0)
        {
            s1.erase(p2,7);flag=1;
        }

        l=s1.length();
        p3=l-5;
        for(int i=0;i<5;i++)
        {
            if(s1[p3+i]!=s4[i])
            {
                f3=1;
            }
        }
        if(f3==0)
        {
            s1.erase(p3,5);
            flag=1;
        }

        l=s1.length();
        p4=l-6;
        for(int i=0;i<6;i++)
        {
            if(s1[p4+i]!=s5[i])
            {
                f4=1;
            }
        }
        if(f4==0)
        {
            s1.erase(p4,6);flag=1;
        }

        if(flag==0&&s1.size()!=0)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        if(s1.size()==0)
        {
            cout<<"YES"<<endl;
            return 0;
        }

    }

}