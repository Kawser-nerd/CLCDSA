#include<stdio.h>
int seq[1000];
int min(int a,int b){
	return a<b?a:b;
}
int main(int argc,char*argv[]){
	int a,b,c,d,e,f,n,ans;
	scanf("%d",&e);
	for(f=1;f<=e;f++){
		scanf("%d",&n);
		for(a=0;a<n;a++){
			scanf("%d",seq+a);
		}
		ans=0;
		while(n!=0){
			b=0;
			for(a=1;a<n;a++){
				if(seq[a]<seq[b])b=a;
			}
			ans+=min(n-1-b,b);
			for(b++;b<n;b++)seq[b-1]=seq[b];
			n--;
		}
		printf("Case #%d: %d\n",f,ans);
	}
	return 0;
}
