#include<stdio.h>
#include<stdlib.h>
int n,m,bat[2008][2],cl[2008][2008][2],c[2008],used[2008];
int check,min;
int an[2008],now[2008];
int rec(int level){
	int i,j,k,l,tmp;
	if(level == 0){
		for(j=0;j<m;j++){
			l = 0;
			for(k=0;k<c[j];k++){
				if(an[cl[j][k][0]] == cl[j][k][1]){
					l = 1;
					break;
				}
			}
			if(l == 0){
				return 0;
			}
		}
		check = 1;
		tmp = 0;
		for(i=0;i<n;i++){
			tmp += an[i];
		}
		if(tmp < min){
			for(i=0;i<n;i++)
				now[i] = an[i];
			min = tmp;
		}
		return 0;
	}
	an[n-level] = 0;
	rec(level - 1);
	an[n-level] = 1;
	rec(level - 1);
	return 0;
}
int main(){
	int t,ca,x,y,i,j;
	scanf("%d",&ca);
	for(t=0;t<ca;t++){
		scanf("%d",&n);
		scanf("%d",&m);
		for(i=0;i<=n;i++)
			bat[i][0] = bat[i][1] = 0;
		for(i=0;i<m;i++){
			scanf("%d",&c[i]);
			for(j=0;j<c[i];j++){
				scanf("%d %d",&cl[i][j][0],&cl[i][j][1]);
				cl[i][j][0]--;
				if(c[i] == 1)
					bat[cl[i][j][0]][cl[i][j][1]] = 1;
			}
		}
		printf("Case #%d: ",t+1);
		for(i=1;i<=n;i++){
			if(bat[i][0] == 1 && bat[i][1] == 1){
				printf("IMPOSSIBLE\n");
				break;
			}
		}
		if(i != n +1){
			continue;
		}
		check = 0;
		min = 2147483647;
		rec(n);
		if(check == 0){
			printf("IMPOSSIBLE\n");
		}else{
			for(i=0;i<n-1;i++)
				printf("%d ",now[i]);
			printf("%d\n",now[n-1]);
		}
	}
	return 0;
}

