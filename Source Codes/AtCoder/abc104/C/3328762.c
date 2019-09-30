#include<stdio.h>
#include<math.h>

int max(int a,int b){
	if(a>b)return a;
	return b;
}

int min(int a,int b){
	if(a<b)return a;
	return b;
}

int main(){
	int D,G,ans=123456789;
	scanf("%d%d",&D,&G);
	int p[D],c[D];
	for(int i=0;i<D;i++)scanf("%d%d",&p[i],&c[i]);
	
	for(int k=0;k<pow(2,D);k++){
		int bit=k;
		int score=0;
		int solved=0;
		int max_not_comp=-1;
		for(int i=0;i<D;i++){
			if(bit%2==1){
				score+=(i+1)*100*p[i]+c[i];
				solved+=p[i];
			}else max_not_comp=max(max_not_comp,i);
			bit/=2;
		}
		if(score<G){
			int req=G-score;
			if(req>(max_not_comp+1)*100*(p[max_not_comp]-1))continue;
			solved+=(req+(max_not_comp+1)*100-1)/((max_not_comp+1)*100);
		}
		ans=min(ans,solved);
	}
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&D,&G);
  ^
./Main.c:18:22: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(int i=0;i<D;i++)scanf("%d%d",&p[i],&c[i]);
                      ^