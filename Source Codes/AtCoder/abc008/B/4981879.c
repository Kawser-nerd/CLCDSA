#include <stdio.h>
int main (void){
	int n,vote[50]={},leng[50]={};
	char name[50][52];
	char dummy;
	scanf("%d",&n);
	scanf("%c",&dummy);
	for(int i=0;i<n;i++){
		for(int k=0;k<51;k++){
			scanf("%c",&name[i][k]);
			leng[i]+=1;
			if(name[i][k]=='\n'){
				leng[i]-=1;
				break;
			}
		}
	}
	int isbreak;
	for(int j=0;j<n;j++){
		for(int i=0;i<n;i++){
			isbreak=1;
			if(leng[i]==leng[j]){
				for(int k=0;k<leng[i];k++){
					if(name[i][k]!=name[j][k]){
						isbreak=0;
					}
				}
				if(isbreak){
					vote[i]+=1;
					break;
				}
			}
		}
		vote[j]+=1;
	}
	int max=-1,maxname;
	for(int i=0;i<n;i++){
		if(max<vote[i]){
			max=vote[i];
			maxname=i;
		}
	}
	for(int i=0;i<leng[maxname];i++){
		printf("%c",name[maxname][i]);
	}
	printf("\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%c",&dummy);
  ^
./Main.c:10:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%c",&name[i][k]);
    ^