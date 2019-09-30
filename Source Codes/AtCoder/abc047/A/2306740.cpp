#include<iostream>
using namespace std;
typedef long long ll;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(a+b==c || a+c==b || b+c==a)
        cout<<"Yes\n";
    else
        cout<<"No\n";
    return 0;
}