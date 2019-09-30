#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int N=50+10;

char arr1[N];
int arr2[N];

int main()
{
    ll a,b,c;
    ll k;
    while(cin>>a>>b>>c){
        cin>>k;
        ll num=a-b;
        if(k%2==1){
            cout<<(num*(-1))<<endl;
        }
        else{
            cout<<num<<endl;
        }
    }


    return 0;
}