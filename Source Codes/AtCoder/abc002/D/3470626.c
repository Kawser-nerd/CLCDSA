#include <stdio.h>
#include <math.h>

int main( void ){
	int n,m,i,j,k,l,a,b,ans=1,flg,flg2,cnt;
	int x[100],y[100],men[16];
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++) scanf("%d%d",&x[i],&y[i]);

	a=pow(2,n);
	for( i=3;i<a;i++ ){
		b=i;
		cnt=0;
		for(j=1;j<=n;j++){
			men[j]=b%2;
			b=b/2;
			if( men[j]==1 ){
				cnt++;
			}
		}
		
		flg=1;
		for(j=1;j<=n-1;j++){
			for(k=j+1;k<=n;k++){
				if( men[j]==1 && men[k]==1 ){
					flg2=0;
					for(l=0;l<m;l++) if( x[l]==j && y[l]==k ) flg2=1;
					if( flg2==0 ){
						flg=0;
						k=n;
						j=n;
					}
				}
			}
		}
		if( flg==1 )
			if( ans<cnt ) ans=cnt;
	}
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&m);
  ^
./Main.c:8:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<m;i++) scanf("%d%d",&x[i],&y[i]);
                   ^