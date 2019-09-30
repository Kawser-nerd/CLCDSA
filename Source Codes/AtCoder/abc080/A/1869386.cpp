#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int s;
    s=a*b;
    if(s<c)
    {
        cout<<s<<endl;
        return 0;
    }
    else if(s>c) 
    {
        cout<<c<<endl;
        return 0;
    }
    else
    {
        cout<<s<<endl;
        return 0;
    }
    return 0;
}