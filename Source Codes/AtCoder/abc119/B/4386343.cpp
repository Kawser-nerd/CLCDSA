#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    int n;
    float sum=0;
    scanf("%d",&n);
    while(n--)
    {
        float x;
        string u;
        cin>>x>>u;
        if(u=="BTC")
            sum+=x*380000.0;
        else
            sum+=x;
    }
    cout<<sum;
    return 0;
}