#include<stdio.h>

void strcopy(char a[],char b[],int k){
	int i;
	for(i=0;i<k;i++)a[i]=b[i];
}

int strcomp(char a[],char b[],int k){
	int i;
	for(i=0;i<k;i++){
		if(a[i]!=b[i])return 1;
	}
	return 0;
}

int main(){
	char s[301],tmple[300][301];
	int k,gen=0,i,count=0,j;;
	scanf("%s%d",s,&k);
	while(s[gen]!=0)gen++;
	if(gen<k){
		puts("0");
		return 0;
	}
	for(i=0;i<=gen-k;i++){
		for(j=0;j<count;j++){
			if(strcomp(&s[i],tmple[j],k)==0){
				break;
			}
		}
		if(j==count){
			strcopy(tmple[count],&s[i],k);
			count++;
		}
	}
	printf("%d\n",count);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s%d",s,&k);
  ^