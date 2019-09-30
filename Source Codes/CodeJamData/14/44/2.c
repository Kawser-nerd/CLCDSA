#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
char s[10][20];
int mo[10],c[5];

int comp(const void *p,const void *q){
	return strcmp((char *)p,(char *)q);
}

int dfs(int d,int k,int a,int b){
	int i,st=-1,pr,res=0;
	for(i=a;i<=b;i++){
		if(mo[i]!=k)continue;
		if(s[i][d]==0)continue;
		if(st==-1){
			st=i;pr=i;
		}else{
			if(s[i][d]!=s[pr][d]){
				res+=(1+dfs(d+1,k,st,pr));
				st=i;
			}
			pr=i;
		}
	}
	if(st==-1)return 0;
	res+=(1+dfs(d+1,k,st,pr));
	return res;
}

int main(){
	int TT,T;
	int m,n,i,j,tmp,flg,res,cnt;
	scanf("%d",&T);
	for(TT=1;TT<=T;TT++){
		scanf("%d%d",&m,&n);
		memset(s,0,sizeof(s));
		for(i=0;i<m;i++)scanf("%s",s[i]);
		qsort(s,m,20,comp);
		res=0;cnt=0;
		for(i=0;i<(int)round(pow(n,m));i++){
			tmp=i;
			memset(c,0,sizeof(c));flg=0;
			for(j=0;j<m;j++){
				mo[j]=tmp%n;
				if(!c[mo[j]]){
					flg++;
					c[mo[j]]=1;
				}
				tmp/=n;
			}
			if(flg<n)continue;
			tmp=0;
			for(j=0;j<n;j++){
				tmp+=dfs(0,j,0,m-1);
			}
			if(res<tmp){
				res=tmp;cnt=1;
			}else if(res==tmp){
				cnt++;
			}
		}
		printf("Case #%d: %d %d\n",TT,res+n,cnt);
	}
	return 0;
}
