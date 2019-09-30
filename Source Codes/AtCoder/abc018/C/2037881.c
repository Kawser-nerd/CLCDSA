#include<stdio.h>
#include<stdlib.h>
int MIN(int a,int b){return a<b?a:b;}
int h,w,n,i,j,k,c=0,d[510][510],l[510][510]={};
int r[510][510]={};
int main(){
	char s[510][510];
	scanf("%d %d %d",&h,&w,&n);
	for(i=0;i<h;i++)scanf(" %s",s[i+1]+1);
	//printf("aa\n");
	for(i=1;i<=h;i++){
		for(j=1;j<=w;j++){
			if(s[i][j]=='x')l[i][j]=0;
			else l[i][j]=l[i][j-1]+1;
		}
		for(j=w;j>0;j--){
			if(s[i][j]=='x')r[i][j]=0;
			else r[i][j]=r[i][j+1]+1;
		}
		for(j=1;j<=w;j++)d[i][j]=MIN(l[i][j],r[i][j]);
	}
	/*for(i=0;i<h;i++){
		for(j=0;j<w;j++)printf("%d ",d[i+1][j+1]);printf("\n");
	}//*/
	for(i=n;i+n-2<h;i++){
		for(j=n;j+n-2<w;j++){
			for(k=-n+1;k<n;k++){//printf("%d %d:",n-abs(k),d[i+k][j]);
				if(d[i+k][j]<abs(n-abs(k)))break;
			}//printf("\n");
			if(k==n)c++;//,printf("%d %d\n",i,j);
		}
	}
	printf("%d\n",c);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d",&h,&w,&n);
  ^
./Main.c:9:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<h;i++)scanf(" %s",s[i+1]+1);
                  ^