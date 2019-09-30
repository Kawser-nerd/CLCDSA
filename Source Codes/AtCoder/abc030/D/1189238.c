#include<stdio.h>
#include<string.h>

int main(void){
	int ss,kl,js,j,n,a,b[131072],f[131072]={0},w[131072]={0},p,i,kk;
	char k[131072];
	scanf("%d%d%s",&n,&a,k);
	for(i = 1;i <= n;i++){scanf("%d",&b[i]);}
	p = a;
	f[p] = 1;
	w[1] = p;
	i = 1;
	while(1){
		i++;
		p = b[p];
		w[i] = p;
		if(f[p] == 1){break;}
		f[p] = 1;
	}
	for(j = 1;j <= i;j++){if(p == w[j]){js = j;break;}}
	js = i - js;
	i = i - js;
	kl = strlen(k);
	p = 0;
	if(kl <= 7){
		for(j = kl-7;j < kl;j++){if(j < 0){continue;}p*=10;p+=k[j];p-=48;}
		if(p < i){printf("%d\n",b[w[p]]);return 0;}
	}
	ss = 1;
	p = js-i;
	for(j = kl-1;j >= 0;j--){p+=(ss*(k[j]-48));p%=js;ss*=10;ss%=js;}
	p+=i;
	printf("%d\n",b[w[p]]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%s",&n,&a,k);
  ^
./Main.c:8:24: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i = 1;i <= n;i++){scanf("%d",&b[i]);}
                        ^