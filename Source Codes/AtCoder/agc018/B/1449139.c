#include<stdio.h>

#define MAXN 300
#define MAXM 300

int main(void){
	int n,m,i,j,k;
	int sp[MAXN][MAXM];
	int manage_rank[MAXM+1],join_num[MAXM+1],subflg[MAXM+1];
	int maxnum=301,tmpmax,tmpsub;
	
	for(i=0;i<MAXN;i++){
		for(j=0;j<MAXM;j++) sp[i][j]=0;
	}
	for(i=0;i<=MAXM;i++){
		manage_rank[i]=0;
		join_num[i]=0;
		subflg[i]=1;
	}
	
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++) for(j=0;j<m;j++) scanf("%d",&sp[i][j]);
	
	for(i=0;i<m;i++){
		tmpmax=-1;
		for(j=0;j<n;j++){
			join_num[sp[j][manage_rank[j]]]++;
		}
		for(j=1;j<=m;j++){
			if(tmpmax<join_num[j]){
				tmpsub=j;
				tmpmax=join_num[j];
			}
		}
		if(tmpmax<maxnum) maxnum=tmpmax;
		//fprintf(stdout,"%d\t maxnum:%d @ %d\n",i,maxnum,tmpsub);
		subflg[tmpsub]=0;
		for(j=1;j<=m;j++) join_num[j]=0;
		for(j=0;j<n;j++){
			while(manage_rank[j]<m && subflg[sp[j][manage_rank[j]]]==0) manage_rank[j]++;
		}
		//for(j=0;j<n;j++) fprintf(stderr,"%d%c",manage_rank[j],(j==n-1)?'\n':' ');
	}
	printf("%d\n",maxnum);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n,&m);
  ^
./Main.c:22:36: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<n;i++) for(j=0;j<m;j++) scanf("%d",&sp[i][j]);
                                    ^