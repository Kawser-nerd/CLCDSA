#include<stdio.h>
#include<stdlib.h>
int main(){
	int T,I;
	scanf("%d",&T);
	for(I=0;I<T;I++){
		int n,x,a[800]={},i,j,s;
		scanf("%d %d",&n,&x);
		for(i=0;i<n;i++){
			scanf("%d",&s);
			a[s]++;
		}
		int now,ans=0;
		while(n>0){
			for(i=x;i>0;i--){
				if(a[i]>0){
					a[i]--;
					now=i;
					n--;
					ans++;
					break;
				}
			}
			for(i=x-now;i>0;i--){
				if(a[i]>0){
					a[i]--;
					n--;
					break;
				}
			}
		}
		printf("Case #%d: %d\n",I+1,ans);
	}
	return 0;
}