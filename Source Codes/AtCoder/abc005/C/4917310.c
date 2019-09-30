#include <stdio.h>

int main(void) {
	int t,n,a[101]={},m,b[100],ans=0;
	scanf("%d %d",&t,&n);
	for (int i=0;i<n;i++)scanf("%d",&a[i]);
	scanf("%d",&m);
	for (int i=0;i<m;i++)scanf("%d",&b[i]);
	
	if (m>n){
		printf("no\n");
		return 0;
	}
	
	int last=0;
	for (int i=0;i<m;i++){
		for (int k=last;k<n;k++){
			if ((b[i]-t)<=a[k]&&b[i]>=a[k]){
				last=k;
				for (int j=last;j<n+1;j++){
					a[j]=a[j+1];
				}
				ans=1;
				break;
			}else ans=0;
		}
		if(ans==0)break;
	}
	if(ans)printf("yes\n");
	else printf("no\n");
	return 0;
		} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&t,&n);
  ^
./Main.c:6:23: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for (int i=0;i<n;i++)scanf("%d",&a[i]);
                       ^
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&m);
  ^
./Main.c:8:23: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for (int i=0;i<m;i++)scanf("%d",&b[i]);
                       ^