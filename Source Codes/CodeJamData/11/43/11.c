#include<stdio.h>
#define M 1001
char npr[M+1];
int prime[M];
int getprime(){
	int i,j;
	for(i=2;i<=M;i++){
		if(!npr[i])
			prime[++prime[0]]=i;
		for(j=1;j<=prime[0] && prime[j]*i<=M;j++){
			npr[prime[j]*i]=1;
			if(i%prime[j]==0)
				break;
		}
	}
}
void getprimefactor(int n,int *k){
	int i=1;
	while(n>1){
		while(n%prime[i]==0){
			n/=prime[i];
			k[i]++;
		}
		i++;
	}
}
int tmp[M+1],max[M+1],pmax[M+1],occur[M+1];
int count[M+1];
int main(){
	getprime();
	int t;
	scanf("%d",&t);
	int pp;
	for(pp=1;pp<=t;pp++){
		int n,i;
		scanf("%d",&n);
		if(n==1){
			printf("Case #%d: 0\n",pp);
			continue;
		}
		for(i=1;i<=prime[0];i++)max[i]=1;
		memset(pmax,0,sizeof(pmax));
		memset(occur,0,sizeof(occur));
		for(i=1;i<=n;i++){
			memset(tmp,0,sizeof(tmp));
			getprimefactor(i,tmp);
			int j;
			for(j=1;j<=prime[0];j++){
				if(tmp[j])occur[j]=1;
				if(tmp[j]>pmax[j]){
					max[j]=i;
					pmax[j]=tmp[j];
				}
			}
		}
		memset(count,0,sizeof(count));
		int ans=0,ans2=0;
		count[0]=1;
		for(i=1;i<=prime[0];i++){
			if(!occur[i])continue;
			if(!count[max[i]]){
				count[max[i]]=1;
				ans++;
			}
			ans2+=pmax[i];
		}
		printf("Case #%d: %d\n",pp,ans2-ans+1);
	}
	return 0;
}
