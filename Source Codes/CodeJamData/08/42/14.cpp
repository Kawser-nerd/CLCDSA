#include<cstdio>
#include<cstring>

bool hash[10000];
int T,i,j,m,n,a,A,B,x1,x2,y1,y2,I;
main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d%d",&n,&m,&a);
		memset(hash,0,sizeof hash);
		for (i=0;i<=n;++i){
			for (j=0;j<=m;++j)
				hash[i*j]=1;
		}
		bool bt=false;
		for (i=0;i+a<=n*m;++i)
			if (hash[i] && hash[i+a]) {bt=true;A=i;B=i+a;break;}
		if (bt){
			for (i=0;i<=n;++i)
		    	for (j=0;j<=m;++j)
		        	if (i*j==A){
						x1=i;y2=j;
					}
					else if (i*j==B){
						x2=i;y1=j;
					}
			printf("Case #%d: ",++I);
			printf("%d %d %d %d %d %d\n",0,0,x1,y1,x2,y2);
		}
		else {
			printf("Case #%d: ",++I);
			printf("IMPOSSIBLE\n");
		}
	}
}
