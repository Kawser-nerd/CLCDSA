#include<stdio.h>

long long yak(long long a,int b){
		if(b==0)return 1;
		return yak(a,b-1)*a;
}
int main(){
		int i,c=0;
		long long n,num[100000][2]={0},j,ans=1,nc;
		scanf("%lld",&n);nc=n;
		if(n==1){
				puts("Deficient");
				return 0;
		}
		for(j=2;j*j<=n;j++){
				if(n%j==0){
						int f=0;
						n/=j;
						for(i=0;i<c;i++){
								if(num[i][0]==j){
										num[i][1]++;
										f=1;
										break;
								}
						}
						if(f==0){
								num[c][0]=j;
								num[c][1]=1;
								c++;
						}
						j=1;
				}
		}
		int f=0;
		for(i=0;i<c;i++){
				if(num[i][0]==n){
						num[i][1]++;
						f=1;
						break;
				}
		}
		if(f==0){
				num[c][0]=n;
				num[c][1]=1;
				c++;
		}
		for(i=0;i<c;i++){
				long long tmp=0;
				for(j=0;j<=num[i][1];j++){
						tmp+=yak(num[i][0],j);
				}
				ans*=tmp;
		}
		if(ans<nc*2)puts("Deficient");
		if(ans==nc*2)puts("Perfect");
		if(ans>nc*2)puts("Abundant");
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&n);nc=n;
   ^