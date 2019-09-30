#include<stdio.h>
int MAX(int a,int b){return a<b?b:a;}
int main(){
	int n,m,y,z,i,j,k,max=-1e9,a,p[20],d[20][2000],dd[2000];
	int u[20][2000]={1};
	char c[20],s[5010];
	scanf("%d %d %d %d",&n,&m,&y,&z);
	for(i=0;i<m;i++)scanf(" %c %d",&c[i],&p[i]);
	for(j=0;j<m;j++){
		for(i=0;i<(1<<m);i++)d[j][i]=-1e9;
	}
	d[0][0]=0;
	scanf("%s",s);
	for(i=0;i<n;i++){
		for(a=0;c[a]-s[i];a++);//printf("%d\n",a);
		int uu[2000]={};
		for(j=0;j<(1<<m);j++)dd[j]=-1e9;
		for(j=0;j<m;j++){
			for(k=1<<m;k--;){
				if(u[j][k]==0)continue;
				uu[k|(1<<a)]=1;
				dd[k|(1<<a)]=MAX(dd[k|(1<<a)],d[j][k]+p[a]+(j==a&&(k&(1<<a))?y:0));
			}
		}
		//for(k=0;k<(1<<m);k++)printf("%d ",dd[k]);printf("\n");
		for(k=0;k<(1<<m);k++){
			d[a][k]=MAX(d[a][k],dd[k]);
			u[a][k]|=uu[k];
		}
		/*for(j=0;j<m;j++){
			for(k=0;k<(1<<m);k++)printf("%2d ",d[j][k]);printf("\n");
		}printf("\n");//*/
	}
	for(i=0;i<m;i++){
		for(k=0;k<(1<<m);k++)max=MAX(max,d[i][k]+(k+1==(1<<m)?z:0));
	}
	printf("%d\n",max);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d %d",&n,&m,&y,&z);
  ^
./Main.c:8:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<m;i++)scanf(" %c %d",&c[i],&p[i]);
                  ^
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^