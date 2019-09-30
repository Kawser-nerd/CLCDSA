#include<stdio.h>
#include<string.h>

int map[1010][1010];

int main()
{
	int tn,n;
	int i,j,k,l;
	int t,m;
	int p,q;
	int now;
	int ans;
	scanf("%d",&tn);
	for(l=1;l<=tn;l++){
		memset(map,0,sizeof(map));
		
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",&m);
			while(m--){
				scanf("%d",&t);
				map[i][t]++;
			}
		}
		ans = 0;
		for(k=1;k<=n && ans==0;k++){
			/*
			printf("k %d:\n",k);
			for(i=1;i<=n;i++){
				for(j=1;j<=n;j++){
					printf("%d ",map[i][j]);
				}
				printf("\n");
			}
			printf("\n");
			*/
			for(i=1;i<=n && ans==0;i++){
				for(j=1;j<=n && ans==0;j++){
					map[i][j] += (map[i][k]*map[k][j]);
					if(map[i][j]>1)ans = 1;
				}
			}
			/*
			for(i=1;i<=n;i++){
				for(j=1;j<=n;j++){
					printf("%d ",dp[i][j]);
				}
				printf("\n");
			}
			*/
		}
		
		
		printf("Case #%d: ",l);
		if(ans)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

