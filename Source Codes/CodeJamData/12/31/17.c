#include <stdio.h>
#include <string.h>
int N,T;
int m[1024][1024];
int count[1024][1024];
int i,j,k,l,n,ca;
char done;
int main()
{
	scanf("%d",&T);
	while(ca++<T){
		done=0;
		memset(m,0,sizeof(m));
		memset(count,0,sizeof(count));
		scanf("%d",&N);
		for(i=1;i<=N;i++){
			scanf("%d", &n);
			for(j=1;j<=n;j++){
				scanf("%d",&l);
				m[i][l]=1;
				count[i][l]=1;
			}
		}
		for(k=1;k<=N;k++){
			for(i=1;i<=N;i++){
				for(j=1;j<=N;j++){
					if(m[i][k] && m[k][j]){
						m[i][j]=1;
						count[i][j]++;
						if(count[i][j]==2)
						{
							done=1;
							goto finish;
						}
					}
				}
			}
		}
finish:
		if(done){
			printf("Case #%d: Yes\n",ca);
		}else{
			printf("Case #%d: No\n",ca);
		}
	}
	return 0;
}
