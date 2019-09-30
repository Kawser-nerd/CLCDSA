#include<stdio.h>
#include<algorithm>
using namespace std;
int b[1100];
int main(){
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		int a;scanf("%d",&a);
		for(int i=0;i<a;i++)scanf("%d",b+i);
		int ret1=0;
		int ret2=0;
		for(int i=1;i<a;i++){
			if(b[i-1]>b[i])ret1+=b[i-1]-b[i];
		}
		int m=0;
		for(int i=1;i<a;i++)m=max(m,b[i-1]-b[i]);
		for(int i=0;i<a-1;i++){
			ret2+=min(b[i],m);
		}
		printf("Case #%d: %d %d\n",t,ret1,ret2);
	}
}