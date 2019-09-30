#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int n,sum,ans;
int main(){
        scanf("%d",&n);
        for(int i=1;i<=n;i+=2){
                for(int j=1;j<=floor(sqrt(i));j++)
                        if(i%j==0)
                                sum++;
                if(sum==4) ans++;
                sum=0;
        }
        printf("%d",ans);
}