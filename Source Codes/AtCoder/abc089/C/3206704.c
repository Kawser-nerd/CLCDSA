#include<stdio.h>

int main(){
	int N;
	scanf("%d",&N);
	long long march[5]={0,0,0,0,0};
	for(int i=0;i<N;i++){
		char name[11];
		scanf("%s",name);
		switch(name[0]){
			case 'M':
				march[0]++;
				break;
			case 'A':
				march[1]++;
				break;
			case 'R':
				march[2]++;
				break;
			case 'C':
				march[3]++;
				break;
			case 'H':
				march[4]++;
				break;
		}
	}
	long long ans=0;
	for(int i=0;i<3;i++){
		for(int j=i+1;j<4;j++){
			for(int k=j+1;k<5;k++){
				ans+=march[i]*march[j]*march[k];
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",name);
   ^