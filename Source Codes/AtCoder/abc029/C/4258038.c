#include<stdio.h>

int ru4(int a){
	int i,r=1;
	for(i=0;i<a;i++)r=r*4;
	return r;
}

int main(){
	int n,i;
	scanf("%d",&n);
	for(i=1;i<ru4(n);i++){
		int tmp[10]={0},cpy=i,j=0;
		for(j=9;j>=0;j--)tmp[j]=-1;
		j=0;
		while(cpy>0){
			tmp[j++]=cpy%4;
			cpy=(cpy-cpy%4)/4;
		}
		int f=0;
		for(j=0;j<10;j++){
			if(tmp[j]==0){
				f=1;
				//break;
			}
			if(n>j&&tmp[j]==-1)f=1;
		}
		if(f==0){
		for(j=9;j>=0;j--){
			if(tmp[j]==1)putchar('a');
			if(tmp[j]==2)putchar('b');
			if(tmp[j]==3)putchar('c');
		}puts("");
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^