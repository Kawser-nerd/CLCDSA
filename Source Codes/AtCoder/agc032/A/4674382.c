#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int order=0;
int Ans[100];

int check(int a[]){
	int i=0,j,b[101];
	if(a[1]==0 && a[0]==1){
		Ans[order++]=1;
		return 0;
	}

	while(a[i]!=0){
		if(i+1<a[i]){
			return -1;
		}
		i++;
	}
	i=0;
	while(a[i]!=0){
		if(i+1==a[i]){
			for(j=0;j<i;j++){
				b[j]=a[j];
			}
			for(j=i;j<=100;j++){
				b[j]=a[j+1];
			}

			if(check(b)==0){
				Ans[order++]=a[i];
				return 0;
			}

		}
		i++;
	}
	return -1;
}

int main(){
	int i,k,N;
	scanf("%d",&N);
	int a[101];

	for(i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	a[N]=0;
	k=check(a);

	if(k==0){
		for(i=0;i<N;i++){
			printf("%d\n",Ans[i]);
		}
	}else{
		printf("-1\n");
	}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:44:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:48:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a[i]);
   ^