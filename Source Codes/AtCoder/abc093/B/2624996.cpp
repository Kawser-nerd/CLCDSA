#include<iostream>
//#include<algorithm>
using namespace std;

long long  a,b,c;
int main(){
    while(cin>>a>>b>>c)
    {
        for(long long  i=a;i<=b;i++)
        {
            if(i<a+c||i>b-c)
                cout<<i<<endl;

        }
    }
   }