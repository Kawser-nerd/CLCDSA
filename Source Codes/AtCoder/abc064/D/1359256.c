#include<stdio.h>

int main(){
	int nn;
	scanf("%d",&nn);
	char a[300];

	int jdl=0;  // judge number left
	int jdr=0;  // judge number right

	scanf("%s",a);

	int i;
	for(i=0;i<nn;i++){
		if(a[i]=='(')
			jdr++;
		else if(jdr>0)
			jdr--;
		else
			jdl++;
	}

	for(i=nn-1;i>=0;i--){
		a[i+jdl]=a[i];
	}
	for(i=0;i<jdl;i++){
		a[i]='(';
	}

	for(i=0;i<jdr;i++){
		a[i+nn+jdl]=')';
	}

	a[nn+jdl+jdr]='\0';

	printf("%s\n",a);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&nn);
  ^
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",a);
  ^