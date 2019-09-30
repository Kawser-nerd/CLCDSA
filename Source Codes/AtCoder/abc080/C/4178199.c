#include<stdio.h>

int main(){
		int n,i,j,k,f[100][10];
		long p[100][11];
		long long ans=-2000000000000;
		scanf("%d",&n);
		for(i=0;i<n;i++){
				for(j=0;j<10;j++){
						scanf("%d",&f[i][j]);
				}
		}
		for(i=0;i<n;i++){
				for(j=0;j<11;j++){
						scanf("%lld",&p[i][j]);
				}
		}
		for(i=1;i<1024;i++){
				int joisino[10];
				int a=i,doko[100]={0};
				long long tmp=0;
				j=0;
				while(a>0){
						joisino[j]=a%2;
						if(a%2==1)a--;
						a=a/2;
						j++;
				}
				for(j=0;j<n;j++){
						for(k=0;k<10;k++){
								if(joisino[k]==1&&f[j][k]==1)doko[j]++;
						}
				}
				for(j=0;j<n;j++)tmp+=p[j][doko[j]];
				if(tmp>ans)ans=tmp;
		}
		printf("%lld\n",ans);
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:13: warning: format ‘%lld’ expects argument of type ‘long long int *’, but argument 2 has type ‘long int *’ [-Wformat=]
       scanf("%lld",&p[i][j]);
             ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:10:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d",&f[i][j]);
       ^
./Main.c:15:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%lld",&p[i][j]);
       ^