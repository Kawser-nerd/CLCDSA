#include<stdio.h>
int main(){
	int count=1;int n;int tmp[60]={-1},now;bool flag=false;
	scanf("%d",&n);
	scanf("%d",&now);
	tmp[0]=now;
	int j;
	for(int i=1;i<n;i++){
		scanf("%d",&now);
		for(j=0;j<count;j++){
			if(tmp[j]>=now){
				flag=true;
				break;
			}
		}
		if(flag){
			tmp[j]=now;
			flag=false;
		}
		else{
			tmp[count++]=now;
			flag=false;
		} 
	}
	printf("%d\n",count);
	return 0;
}