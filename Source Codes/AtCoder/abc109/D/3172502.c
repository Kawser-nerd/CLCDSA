#include<stdio.h>

int main(){
	int h,w;
	scanf("%d%d",&h,&w);
	int a[h][w],i,j,ans[h*w][4],counter=0;//long n=0;
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			scanf("%d",&a[i][j]);
	//		n+=(a[i][j]%2);
		}
	}
	//printf("%ld\n",n);
	for(i=h-1;i>0;i--){
		for(j=0;j<w;j++){
			if(a[i][j]!=0){
				while(a[i][j]%2==1){
					a[i][j]-=1;
					a[i-1][j]+=1;
					ans[counter][0]=i+1;
					ans[counter][1]=j+1;
					ans[counter][2]=i;
					ans[counter][3]=j+1;
					counter++;
			}
			}
		}
	}
	for(i=w-1;i>0;i--){
		while(a[0][i]%2==1){
			a[0][i]-=1;
			a[0][i-1]+=1;		
			ans[counter][0]=1;
			ans[counter][1]=i+1;
			ans[counter][2]=1;
			ans[counter][3]=i;
			counter++;
		}
	}
	printf("%d\n",counter);
	for(i=0;i<counter;i++){
			printf("%d %d %d %d\n",ans[i][0],ans[i][1],ans[i][2],ans[i][3]);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&h,&w);
  ^
./Main.c:9:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&a[i][j]);
    ^