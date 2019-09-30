#include<stdio.h>

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

struct p{
		int b;
		long long money;
		int koho[20];
		int count;
};

int main(){
		long long ans;
		int n,i;
		struct p shine[20];
		scanf("%d",&n);
		for(i=1;i<n;i++){
				scanf("%d",&shine[i].b);
				shine[i].b--;
				shine[i].count=0;
		}
		shine[0].b=-1;
		int j;
				for(i=0;i<n;i++){
						for(j=0;j<n;j++){
								if(shine[i].b==j){
										shine[j].koho[shine[j].count++]=i;
								}
						}
				}
				for(i=0;i<n;i++){
//								printf("%d,",shine[i].count);
						if(shine[i].count==0){
								shine[i].money=1;
						}
				}//puts("");
		for(j=0;j<n;j++){
				int ma=-2,tmp;
		for(i=0;i<n;i++){
//				printf("shine[%d].b:%d\n",i,shine[i].b);
				if(ma<shine[i].b){
						ma=shine[i].b;
						tmp=i;
				}
		}
		if(ma==-1)break;
				long long mx=0,mn=1000000000;
				if(shine[ma].count>0){
		for(i=0;i<shine[ma].count;i++){
				if(mx<shine[shine[ma].koho[i]].money)mx=shine[shine[ma].koho[i]].money;
				if(mn>shine[shine[ma].koho[i]].money)mn=shine[shine[ma].koho[i]].money;
		}
		shine[ma].money=mx+mn+1;
				}
//		printf("%d,\n",ma);
		shine[tmp].b=-2;
		}
//				for(j=0;j<n;j++)printf("%d,%d\n",shine[j].money,shine[j].count);
		printf("%lld\n",shine[0].money);
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&shine[i].b);
     ^