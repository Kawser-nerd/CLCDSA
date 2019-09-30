#include <stdio.h>
#include <string.h>
int t,x,y;
int main(){
	freopen("B-small.in","r",stdin);
	freopen("B.out","w",stdout);
	int i,j;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d %d",&x,&y);
		printf("Case #%d: ",i+1);
		if(x > 0){
			for(j=1;j<=x;j++){
				printf("WE");
			}
		}
		else{
			x = -x;
			for(j=1;j<=x;j++){
				printf("EW");
			}
		}
		if(y > 0){
			for(j=1;j<=y;j++){
				printf("SN");
			}
		}
		else{
			y = -y;
			for(j=1;j<=y;j++){
				printf("NS");
			}
		}
		printf("\n");
	}
	return 0;
}
