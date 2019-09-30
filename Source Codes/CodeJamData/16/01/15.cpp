#include<stdio.h>
int n,T;
int main(){
	scanf("%d",&T);
	for(int tt=1;tt<=T;++tt){
		scanf("%d",&n);
		printf("Case #%d: ",tt);
		if(!n){
			printf("INSOMNIA\n");
		}
		else{
			int mask=0;
			int tmp=0;
			while(mask!=1023){
				tmp+=n;
				int v=tmp;
				while(v) mask|=1<<(v%10),v/=10;
			}
			printf("%d\n",tmp);
		}
	}
	return 0;
}
