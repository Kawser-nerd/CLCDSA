#include<stdio.h>


int main(int argc, char const *argv[]){
	int n,i,o[27],j,p[27];
	char s[51];
	scanf("%d",&n);
	for(i=0;i<27;i++){
		o[i]=51;
	}
	for(i=0;i<n;i++){
		scanf("%s",s);
		for(j=0;j<27;j++){
			p[j]=0;
		}
		j=0;
		while(s[j]!='\0'){
			p[s[j]-'a']++;
			j++;
		}
		for(j=0;j<27;j++){
			o[j]=(p[j]<o[j])?p[j]:o[j];
		}
	}
	for(i=0;i<27;i++){
		for(j=0;j<o[i];j++){
			printf("%c",'a'+i);
		}
	}
	printf("\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^