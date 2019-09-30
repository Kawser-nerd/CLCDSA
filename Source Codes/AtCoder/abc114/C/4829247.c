#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int temp[1048577]={};
int x[4]={0,3,5,7};
int tempnum= 0;
void puttotemp(int k){
	temp[tempnum] = k;
	tempnum++;
}
void maketemp(int a,int n,int k){
	//????k?3?5?7???
	//n???????
	if(n > a){
		return;
	}
	puttotemp(k*10+3);
	maketemp(a,n+1,k*10+3);
	puttotemp(k*10+5);
	maketemp(a,n+1,k*10+5);
	puttotemp(k*10+7);   
	maketemp(a,n+1,k*10+7);
}

int main(void){
	int N;
	scanf("%d",&N);
	int i,j,x;
	int flag,threeflag,fiveflag,sevenflag;
	char s[11];
	snprintf(s,11,"%d",N);//s??N???
	int n = strlen(s);//n??N??????
	int ans = 0;
	maketemp(n,1,0);
	//printf("n = %d\n",n);
	for(i=0;i<1048576;i++){
		if( N >= temp[i]){
		}else{
			continue;
		}
		//s?0????753???????
		snprintf(s,11,"%d",temp[i]);//
		flag = 0;threeflag=0;fiveflag=0;sevenflag=0;
		for(j=0;j<strlen(s);j++){
			if(s[j]=='7'){
				sevenflag=1;
			}else if(s[j]=='5'){
				fiveflag = 1;
			}else if(s[j]=='3'){
				threeflag= 1;
			}else{
				flag = -1;
			}
		}
		if(flag == 0 && sevenflag==1 && fiveflag ==1 && threeflag ==1){
			ans++;
		}
		
	}
	printf("%d",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:28:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^