#include<stdio.h>
int MIN(int a,int b){return a<b?a:b;}
int main(){
	int n,m,i,j,k,d[110][110],a[1010],b[1010],c[1010],s=0;
	scanf("%d %d",&n,&m);
	for(i=0;i<n*n;i++)d[i%n][i/n]=(i%(n+1))?1e9:0;
	for(i=0;i<m;i++){
		scanf("%d %d %d",&a[i],&b[i],&c[i]);
		a[i]--;
		b[i]--;
		d[a[i]][b[i]]=d[b[i]][a[i]]=c[i];
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			for(k=0;k<n;k++)d[j][k]=MIN(d[j][k],d[j][i]+d[i][k]);
		}
	}
	for(i=0;i<m;i++){
		if(c[i]-d[a[i]][b[i]])s++;
	}
	printf("%d\n",s);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n,&m);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&a[i],&b[i],&c[i]);
   ^