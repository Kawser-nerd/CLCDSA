#include <stdio.h>
#include <string.h>


int main(void){
	char str[200000];
	scanf("%s",str);
	long long length=strlen(str);
	char abc[26]="abcdefghijklmnopqrstuvwxyz";
	long long count[26];
	long long temp=0;
	for(int i=0;i<26;i++){
		for(int j=0;j<length;j++){
			if(str[j]==abc[i]) temp++;
		}
		count[i]=temp;
		temp=0;
	}
	long long sum=0;
	for(int i=0;i<26;i++){
		if(count[i]>1) sum+=count[i]*(count[i]-1)/2;
	}

	printf("%lld",length*(length-1)/2+1-sum);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",str);
  ^