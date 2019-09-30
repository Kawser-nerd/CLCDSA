#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    long long  a[4];
    while(cin>>a[0]>>a[1]>>a[2])
    {
      sort(a,a+3);
      if(a[0]==5&&a[1]==5&&a[2]==7)
        cout<<"YES"<<endl;
      else
        cout<<"NO"<<endl;
    }
    return 0;
}