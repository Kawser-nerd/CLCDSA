#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n,x=0,y=0;
    string s;
    cin>>n;
    cin>>s;
    for(int i=0 ; i<n ; i++)
    {
        if(s[i]=='I') {x+=1; y=max(y,x);}
        else          {x-=1; y=max(y,x);}
    }
    cout << y << endl;
    return 0;
}