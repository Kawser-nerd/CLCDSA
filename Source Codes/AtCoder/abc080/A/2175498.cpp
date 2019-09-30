#include <iostream>
#include<cmath>
using namespace std;
int min(int x,int y)
{
    if(x>y)return y;
    else return x;
}
int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    cout<<min(n*a,b)<<endl;
    return 0;
}