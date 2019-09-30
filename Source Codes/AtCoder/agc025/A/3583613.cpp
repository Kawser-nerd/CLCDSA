#include<stdio.h>
#include<string.h>
#include<iostream>
#define ll long long
using namespace std;

int hehe(int n){
    int ans=0;
    while(n)
    {
    ans+=n%10;n/=10;}
    return ans;
}

int main (){
    int n;
    scanf("%d",&n);
    int ans=0x3f3f3f3f;
    for(int i=1;i<n;i++){
        ans=min(hehe(i)+hehe(n-i),ans);
    }
    printf("%d\n",ans);
    return 0;
}