#include<stdio.h>
int n1,m1,n2,m2;
int a[101][101],b[101][101];
inline void work1(){
	int i,j;
	for(i=n1;i<=n2;i++)
	for(j=m1;j<=m2;j++)
		if(a[i-1][j] && a[i][j-1])b[i][j]=1;
		else if((a[i-1][j] || a[i][j-1])&&a[i][j])b[i][j]=1;
		else b[i][j]=0;
	memcpy(a,b,sizeof b);
}
inline void read1(){
	int r;
	scanf("%d",&r);
	int i;
	for(i=1;i<=r;i++){
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if(x1<n1)n1=x1;
		if(x2>n2)n2=x2;
		if(y1<m1)m1=y1;
		if(y2>m2)m2=y2;
		int j,k;
		for(j=x1;j<=x2;j++)
		for(k=y1;k<=y2;k++)
			a[j][k]=1;
	}
}
int main(){
	int c;
	scanf("%d",&c);
	int t;
	for(t=1;t<=c;t++){
		n1=m1=101;
		n2=m2=0;
		memset(a,0,sizeof a);
		read1();
		int cc=0;
		for(;1;){
			cc++;
			work1();
			int i,j,flag=1;
			for(i=n1;i<=n2;i++){
				for(j=m1;j<=m2;j++)
				if(a[i][j]){
					flag=0;
					break;
				}
				if(!flag)break;
			}
			if(flag){
				printf("Case #%d: %d\n",t,cc);
				break;
			}
		}
	}
	return 0;
}

