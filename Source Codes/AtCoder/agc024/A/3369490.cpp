#include<iostream>
using namespace std;
int main(){
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    if(d&1)cout<<b-a<<endl;
    else cout<<a-b<<endl;
    return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010],n;
#define ll long long
bool cmp(int A,int B){
    return a[A]<a[B];
}
ll cal(ll a){
    a=2*a+1;
    if(a<=n)return a;
    else return 2*n+1-a;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++)b[i]=i;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(b,b+n,cmp);
   // for(int i=0;i<n;i++)cout<<b[i]<<" ";cout<<endl;
    ll now=0,goal=((ll)n*(n-1)/2+n)/2+1;
    for(int i=0;i<n;i++){
        now+=cal(b[i]);
       // cout<<now<<"-----"<<goal<<endl;
        if(now>=goal){
            cout<<a[b[i]]<<endl;
            return 0;
        }
    }
    return 0;
}*/