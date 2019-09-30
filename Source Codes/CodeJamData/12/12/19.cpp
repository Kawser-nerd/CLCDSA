#include<stdio.h>
int n;
int a[2000],b[2000],u[2000];
int main(){
	int _,t;
	scanf("%d",&_);
	for(t=1; t<=_; t++){
		scanf("%d",&n);
		for(int i=0; i<n; i++){
			scanf("%d%d",&a[i],&b[i]);
			u[i]=0;
		}
		int tot=0,ans=0;
		while(1){
			int p=-1;
			bool flag=true;
			for(int i=0; i<n; i++)
				if(u[i]<2){
					flag=false;
					if(b[i]<=tot){
						p=i;
						break;
					}
				}
			if(flag)break;
			if(p!=-1){
				tot+=2-u[p];
				u[p]=2;
				ans++;
				continue;
			}
			for(int i=0; i<n; i++)
				if(u[i]==0 && a[i]<=tot){
					if(p==-1 || b[p]<b[i])
						p=i;
				}
			if(p==-1)break;
			u[p]=1;
			tot++;
			ans++;
		}
		printf("Case #%d: ",t);
		if(tot==2*n)printf("%d\n",ans);else
			puts("Too Bad");
	}
	return 0;
}
