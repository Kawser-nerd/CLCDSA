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
    int m;
    scanf("%d",&m);
    int ans=0x3f3f3f3f;
    for(int i=1;i<m;i++){
        ans=min(hehe(i)+hehe(m-i),ans);
    }
    printf("%d\n",ans);
    return 0;
}