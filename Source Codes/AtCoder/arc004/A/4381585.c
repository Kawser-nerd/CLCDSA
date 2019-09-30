#include<stdio.h>
#include<math.h>

#define max(a,b) ((a)>(b)?(a):(b))

int main(){
	int n,i,j,xy[100][2],ans=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d%d",&xy[i][0],&xy[i][1]);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			ans=max(ans,(xy[i][0]-xy[j][0])*(xy[i][0]-xy[j][0])+(xy[i][1]-xy[j][1])*(xy[i][1]-xy[j][1]));
		}
	}
	printf("%.5lf\n",sqrt(ans));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:9:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<n;i++)scanf("%d%d",&xy[i][0],&xy[i][1]);
                  ^