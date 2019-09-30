#include <iostream>
using namespace std;
#define ll long long
#include <string>
#include <algorithm>
struct s1
{
    int a;
    int b;
    int c;
};

int main()
{
    int a,b;
    cin>>a>>b;
    if(a==1&&b==1)
    {
        cout<<"Draw";
    }
    else if(a==1)
    {
        cout<<"Alice";
    }
    else if(b==1)
    {
        cout<<"Bob";
    }
    else if(a>b)
    {
        cout<<"Alice";
    }
    else if(a==b)
    {
        cout<<"Draw";
    }
    else
    {
        cout<<"Bob";
    }
    return 0;
}