#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#define ll long long
int main()
{
    ll sx,sy,x,y;
    ll mx,my;
    cin>>sx>>sy>>x>>y;
    mx=sx;my=sy;
    while(my!=y)
    {
            if(my<y)
            {
                my++;
                cout<<"U";
                continue;
            }
    }

    while(mx!=x)
    {
        if(mx<x)
        {
            mx++;
            cout<<"R";
            continue;
        }
    }
    while(my!=sy)
    {
            if(my>sy)
            {
                my--;
                cout<<"D";
                continue;
            }
    }
       while(mx!=sx)
    {
        if(mx>sx)
        {
            mx--;
            cout<<"L";
            continue;
        }
    }
    cout<<"L";
    for(int i=0;i<y-sy+1;i++)
    {
        cout<<"U";
    }
    for(int i=0;i<x-sx+1;i++)
    {
        cout<<"R";
    }
    cout<<"DR";
    for(int i=0;i<y-sy+1;i++)
    {
        cout<<"D";
    }
     for(int i=0;i<x-sx+1;i++)
    {
        cout<<"L";
    }
    cout<<"U";
    return 0;
}