#include<cstdio>
#include<iostream>
using namespace std;
int sx,sy,tx,ty;
int main()
{
    while(scanf("%d%d%d%d",&sx,&sy,&tx,&ty)!=EOF)
    {
        for(int i=sy;i<=ty-1;i++)
        {
            cout<<"U";
        }
        for(int i=sx;i<=tx-1;i++)
        {
            cout<<"R";
        }
        for(int i=ty-1;i>=sy;i--)
        {
            cout<<"D";
        }
        for(int i=tx-1;i>=sx;i--)
        {
            cout<<"L";
        }
        cout<<"L";
        for(int i=sy;i<=ty;i++)
        {
            cout<<"U";
        }
        for(int i=sx;i<=tx;i++)
        {
            cout<<"R";
        }
        cout<<"D";
        cout<<"R";
        for(int i=ty;i>=sy;i--)
        {
            cout<<"D";
        }
        for(int i=tx;i>=sx;i--)
        {
            cout<<"L";
        }
        cout<<"U";
    }
}