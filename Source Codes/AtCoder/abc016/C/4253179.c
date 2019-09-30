#include<stdio.h>

struct hit{
	int ttom;
	int a[11];
	int b[11];
	int c;
	int num;
};

int main(){
	int n,m,i,j;
	struct hit a[10];
	int ab[2];
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		a[i].c=0;
		a[i].ttom=0;
		a[i].num=i;
		for(j=0;j<=10;j++)a[i].a[j]=-1;
		for(j=0;j<=10;j++)a[i].b[j]=-1;
	}
	for(i=0;i<m;i++){
		scanf("%d%d",&ab[0],&ab[1]);
		a[ab[0]-1].a[ab[1]]=1;
		a[ab[1]-1].a[ab[0]]=1;
	}
	for(i=0;i<n;i++){
		for(j=1;j<=n;j++){
			if(a[i].a[j]==1){
				int k;
				for(k=1;k<=n;k++){
					if(k!=i+1&&a[j-1].a[k]==1&&a[i].a[k]!=1&&a[i].b[k]!=1){
						a[i].ttom++;
						a[i].b[k]=1;
					}
				}
			}
		}
	}
	for(i=0;i<n;i++)printf("%d\n",a[i].ttom);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&m);
  ^
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&ab[0],&ab[1]);
   ^