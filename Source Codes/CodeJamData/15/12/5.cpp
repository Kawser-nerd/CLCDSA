#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
int c[1100];
int main(){
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=0;i<a;i++)scanf("%d",c+i);
		long long left=0;
		long long right=10000000000000000LL;
		while(left+1<right){
			long long M=(left+right)/2;
			long long num=0;
			for(int i=0;i<a;i++){
				num+=(M+c[i]-1)/c[i];
			}
			if(num>=b)right=M;
			else left=M;
		}
		long long now=0;
		for(int i=0;i<a;i++)now+=(left+c[i]-1)/c[i];
		b-=now;
		int cnt=0;
		for(int i=0;i<a;i++){
			if(left%c[i]==0){
				cnt++;
				if(cnt==b){
					printf("Case #%d: %d\n",t,i+1);
					break;
				}
			}
		}
	}
}