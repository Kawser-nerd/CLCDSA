#include <stdio.h>
#include <stdlib.h>
int min(int x, int y){return x<y?x:y;}
int main(void){
	int n,i,j,k,score=-1e9,l,r,a[50],s[50][50][2]={0};
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	for(i=0;i<n;i++){//takahashi
		for(j=0;j<n;j++){//aoki
			if(i!=j)for(k=0;k<=abs(i-j);k++)s[i][j][k%2] += a[k+min(i,j)];
			else{
				s[i][j][0] = -1e9;
				s[i][j][1] = -1e9;
			}
		}
	}
	for(i=0;i<n;i++){
		int tmp = 0;
		for(j=0;j<n;j++)
			if(s[i][tmp][1] < s[i][j][1])tmp = j;
		if(s[i][tmp][0] > score) score = s[i][tmp][0];
		
	}
	printf("%d\n",score);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:7:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<n;i++)scanf("%d",&a[i]);
                  ^