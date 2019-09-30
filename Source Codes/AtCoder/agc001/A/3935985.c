#include<stdio.h>

int main(){
	int n,i,j,l[200],ans=0;
	scanf("%d",&n);
	for(i=0;i<2*n;i++)scanf("%d",&l[i]);
	for(i=0;i<2*n;i++){
		for(j=0;j<2*n;j++){
			if(l[i]<l[j]){
				int tmp=l[i];
				l[i]=l[j];
				l[j]=tmp;
			}
		}
	}
	for(i=0;i<2*n;i+=2)ans+=l[i];
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:6:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<2*n;i++)scanf("%d",&l[i]);
                    ^