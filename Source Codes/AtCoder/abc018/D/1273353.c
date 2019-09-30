#include<stdio.h>
int main(){
	int n,m,p,q,k,s,i,j,l,a[10010],b[10010],c[10010],d[20],t,max=0;
	scanf("%d %d %d %d %d",&n,&m,&p,&q,&k);
	for(i=0;i<k;i++)scanf("%d %d %d",&a[i],&b[i],&c[i]);
	for(i=0;i<(1<<n);i++){
		s=0;
		for(j=i;j;j/=2)s+=j%2;
		if(s-p)continue;
		for(j=0;j<m;j++)d[j]=0;
		for(j=0;j<k;j++){
			if(i&(1<<(a[j]-1)))d[b[j]-1]+=c[j];
		}
		for(j=0;j<m;j++){
			t=d[j];
			for(l=j;l&&d[l-1]<t;l--)d[l]=d[l-1];
			d[l]=t;
		}
		//for(j=0;j<k;j++)printf("%d ",d[j]);printf("\n");
		for(j=s=0;j<q;j++)s+=d[j];
		if(max<s)max=s;
	}
	printf("%d\n",max);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d %d %d",&n,&m,&p,&q,&k);
  ^
./Main.c:5:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<k;i++)scanf("%d %d %d",&a[i],&b[i],&c[i]);
                  ^