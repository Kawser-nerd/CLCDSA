#include<stdio.h>
int f[100];

void solve(int n,int l,int h){

int i,j,stop=0;

	for(i=l;i<=h;i++){
		if(stop){
			break;
		}
		for(j=0;j<n;j++){
			if((f[j]%i) == 0 || (i%f[j]) == 0){
				stop = 1;
			}else{
				stop=0;
				break;
			}
		}
	}
	
	if(stop)
		printf("%d\n",i-1);
	else
		printf("NO\n");
}

int main(){
	int t,n,i,j,r,c,l,h;

	scanf("%d",&t);

	for(i=1;i<=t;i++){
		scanf("%d",&n);
		scanf("%d",&l);
		scanf("%d",&h);
		for(j=0;j<n;j++){
			scanf("%d",&f[j]);
		}
		printf("Case #%d: ",i);
		solve(n,l,h);
	}
return 0;
}