#include<stdio.h>
int ans=11111;
int dfs(int depth,int use[],int d,int g,int p[],int c[]){
	int i,j;
	int count=0;
	int plus=0;
	int all=0;
	if(depth==d){
		for(i=0;i<d;i++){
			if(use[i]==1){
				count+=p[i];
				plus+=(100*(i+1)*p[i])+c[i];
			}
		}
		if(g>plus){
			for(i=d-1;i>=0;i--){
				if(use[i]==0){
					for(j=0;j<p[i];j++){
						if(g>plus){
						plus+=100*(i+1);
						count++;
						all++;
						}
					}
					if(all==p[i])count=22222;
					break;
				}
			}
		}
		if(count<ans)ans=count;
		return 0;
	}	
	
	use[depth]=1;
	dfs(depth+1,use,d,g,p,c);
	use[depth]=0;
	dfs(depth+1,use,d,g,p,c);
}

int main(){
	int i,d,g,p[11],c[11];
	int use[11]={};
	
	scanf("%d %d",&d,&g);
	
	for(i=0;i<d;i++){
		scanf("%d %d",&p[i],&c[i]);
	}
	dfs(0, use, d, g, p, c);
	
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:44:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&d,&g);
  ^
./Main.c:47:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&p[i],&c[i]);
   ^