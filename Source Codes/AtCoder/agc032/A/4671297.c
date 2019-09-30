#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int now;
	int b;
}data;

int main(void){
	int i,j,N;
	data a[100];
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&a[i].b);
		a[i].now = i+1;
	}
	int ans[N],ok=1,k=0;
	for(i=N-1;i>=0;i--){
		ok=0;
		for(j=N-1;j>=0;j--){
			if(a[j].b==a[j].now){
				ok=1;
				ans[k++]=a[j].b;
				a[j].now = -1;
				break;
			}else{
				a[j].now--;
			}
		}
		if(!ok)break;
	}
	if(!ok)printf("-1");
	else for(i=N-1;i>=0;i--)printf("%d\n",ans[i]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a[i].b);
   ^