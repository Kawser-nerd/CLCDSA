#include<stdio.h>

int main(){
	long long m=1e9+7;
    int n;
	int a[100000];
	scanf("%d",&n);
    for(int i=2;i<=n;i++){
    	int x=i;
        for(int j=2;j<=x;j++){
            while(x%j==0){
                a[j]++;
                x/=j;
            }
        }
    }
    long long res=1;
    for(int i=1;i<=n;i++){
        if(a[i]!=0){
        	res=(res*(a[i]+1))%m;
		}
    }
    printf("%lld",res);
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^