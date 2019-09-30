#include<stdio.h>
#include<stdlib.h>
int fi[10000][2];

int intcmp(const int*a,const int*b){
	if(a[0]==b[0])return 0;
	return a[0]>b[0]?1:-1;
}

int main(int argc,char*argv[]){
	int n,m,a,b,c,e,f,ans;
	scanf("%d",&f);
	for(e=1;e<=f;e++){
		scanf("%d%d",&n,&m);
		for(a=0;a<n;a++){
			scanf("%d",fi[a]+0);
			fi[a][1]=0;
		}
		qsort(fi,n,sizeof(int)*2,intcmp);
		ans=0;
		for(a=n-1;a>=0;a--){
			if(fi[a][1]==1)continue;
			c=-1;
			for(b=a-1;b>=0;b--){
				if(fi[b][1]!=0)continue;
				if(fi[a][0]+fi[b][0]>m)continue;
				c=b;
				break;
			}
			if(c!=-1){
				fi[c][1]=fi[a][1]=1;
			}
			ans++;
		}
		printf("Case #%d: %d\n",e,ans);
	}
	return 0;
}
