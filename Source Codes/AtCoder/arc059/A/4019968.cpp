#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    int a[1000];
    while(cin>>n)
    {
        int sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];            
        }
        sum=(sum+n-1)/n;
        int ans1=0,ans2=0;
        for(int i=0;i<n;i++)
        {
            ans1+=(a[i]-sum)*(a[i]-sum);
            ans2+=(a[i]-sum+1)*(a[i]-sum+1);
        }
        cout<<min(ans1,ans2)<<endl;
    }
    return 0;
}