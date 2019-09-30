#include <iostream>
using namespace std;
#include <algorithm>
#include <string>
#include <vector>
#define ll long long
struct s1
{
    char name[100];
};
int main()
{

    ll a,b;
    char c;
    cin>>a>>c>>b;
    ll d;
    if(c=='+')
        d=a+b;
    else
        d=a-b;
    cout<<d;
    return 0;
}