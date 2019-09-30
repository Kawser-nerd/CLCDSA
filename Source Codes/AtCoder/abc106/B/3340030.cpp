#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int n;
int ans;
int main(){
	scanf("%d",&n);
	if(n<105){
		printf("0");
		return 0;
	}
	if(n<135){
		printf("1");
		return 0;
	}
	if(n<165){
		printf("2");
		return 0;
	}
	if(n<189){
		printf("3");
		return 0;
	}
	if(n<195){
		printf("4");
		return 0;
	}
	printf("5");
	/*
	for(int i=1;i<=n;i+=2){
		int sum=0;
		for(int j=1;j<=i;j++){
			if((i%j)==0)sum++;
		}
		ans+=(sum==8);
	}
	printf("%d",ans);
	*/
}