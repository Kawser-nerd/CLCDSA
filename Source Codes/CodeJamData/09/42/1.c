#include<stdio.h>

int dp[52][52][52][52];
int r,c,f;
char ch[52][52];
unsigned long long map[52],mask[52][52],check[52];

void gen(){
	int i,j,k;
	for(i=0;i<50;i++)for(j=i;j<50;j++){
		mask[i][j]=1ULL;
		for(k=0;k<j-i;k++)mask[i][j]=(mask[i][j]<<1)+1;
		for(k=0;k<i;k++)mask[i][j]<<=1;
		if(i==j)check[i]=mask[i][j];
	}
}

void update(int i,int j,int k,int l,int score){
	int now=1;
	while(~map[i+now]&(check[l]))++now;
	if(now>f)return;
	if(now==1&&dp[i+now-1][j][k][l]>score){
		dp[i+now-1][j][k][l]=score;
  //		printf("%d %d %d %d %d\n",i+now-1,j,k,l,score);
	}
	if(now>1&&dp[i+now-1][l][l][l]>score){
		dp[i+now-1][l][l][l]=score;
//  		printf("%d %d %d %d %d\n",i+now-1,l,l,l,score);
	}
}

int main(){
	int t,ans;
	int x,i,j,k,l,min,max,left,right,y,z,sc;
	scanf("%d",&t);
	gen();
	for(x=0;x<t;x++){
		scanf("%d%d%d",&r,&c,&f);
		for(i=0;i<r;i++){
			map[i]=0;
			scanf("%s",ch[i]);
			for(j=0;j<c;j++)
				if(ch[i][j]=='#')map[i]|=check[j];
//  			printf("%llu\n",map[i]);
		}
		map[r]=(check[c+1])-1;
		for(i=0;i<50;i++)for(j=0;j<50;j++)for(k=0;k<50;k++)for(l=0;l<50;l++)
			dp[i][j][k][l]=99999;
		dp[0][0][0][0]=0;
		for(i=0;i<r-1;i++){
			for(j=0;j<c;j++)
				for(k=j;k<c;k++)
					for(l=j;l<=k;l++){
						if(dp[i][j][k][l]>=99999)continue;
//  						printf("%d %d %d %d %d -- \n",i,j,k,l,dp[i][j][k][l]);
						unsigned long long a = (map[i]&~mask[j][k]);
						min=l;max=l;
						while(min>0&&((~a)&(check[min-1]))&&(map[i+1]&(check[min-1])))--min;
						while(max<c-1&&((~a)&(check[max+1]))&&(map[i+1]&(check[max+1])))++max;
						sc = dp[i][j][k][l];
						for(z=min;z<=max;z++){
							if(dp[i][j][k][z]<sc)
								sc=dp[i][j][k][z];
							dp[i][j][k][z]=99999;
						}
 // 						printf("%d %d %d %d %d -2 \n",i,j,k,l,sc);
 // 						printf("%d %d\n",min,max);
						if(min>0&&!(a&(check[min-1]))&&!(map[i+1]&(check[min-1])))update(i+1,min-1,min-1,min-1,sc);
						if(max<c-1&&!(a&(check[max+1]))&&!(map[i+1]&(check[max+1])))update(i+1,max+1,max+1,max+1,sc);
						left=min;//-1;if(min==0)left=0;
						for(y=left;y<max;y++)
							for(z=y;z<max;z++)
								if(!(a&check[z]))
								update(i+1,y,z,z,sc+z-y+1);
						right=max;//+1;if(right==c)right=c-1;
						for(y=right;y>min;y--)
							for(z=y;z>min;z--)
								if(!(a&check[z]))
								update(i+1,z,y,z,sc+y-z+1);
					}
		}

		ans=99999;
		for(j=0;j<c;j++)
			for(k=j;k<c;k++)
				for(l=j;l<=k;l++)
					if(ans>dp[r-1][j][k][l])ans=dp[r-1][j][k][l];
		if(ans<99999)printf("Case #%d: Yes %d\n",x+1,ans);
		else printf("Case #%d: No\n",x+1);
//  		printf("-------------------\n");
	}
	return 0;
}
