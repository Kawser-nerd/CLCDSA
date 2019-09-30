#include <stdio.h>
#include <stdlib.h>

void doTestCase();

int main(){
	int i,n;
	scanf("%d",&n);
	for (i=1;i<=n;i++){
		printf("Case #%d: ",i);
		doTestCase();
	}
	return 0;
}

void doTestCase(){
	int n,k,b,t;
	scanf("%d %d %d %d",&n,&k,&b,&t);
	
	int pos[n],vel[n];	
	//int arrG[n];
	int i,j,res,sum;
	for (i=0;i<n;i++)
		scanf("%d",pos+i);
	for (i=0;i<n;i++)
		scanf("%d",vel+i);
	
	res=0;
	sum=0;
	j=0;
	for (i=n-1;i>=0;i--){
		if (pos[i]+vel[i]*t>=b){
			//arrG[i]=sum;
			//printf("%d ",i);
			res+=sum;
			j++;
			if (j==k)
				break;
		}
		else{
			sum++;
		}
	}
	if (j==k)
		printf("%d\n",res);
	else
		printf("IMPOSSIBLE\n");
}
