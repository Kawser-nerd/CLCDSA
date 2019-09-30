#include<stdio.h>//atcoder012B
int main(void)
{
	int n,h=0,m=0,s=0;
	scanf("%d",&n);
	h=n/3600;
	m=(n-(h*3600))/60;
	s=n-((h*3600)+(m*60));
	if(h<10 && m<10 && s<10){
		printf("0%d:0%d:0%d",h,m,s);
	}
	else if(10<=h && 10<=m && 10<=s){
		printf("%d:%d:%d\n",h,m,s);
	}
	else if(h<10 && 10<=m && 10<=s){
		printf("0%d:%d:%d",h,m,s);
	}
	else if(10<=h && m<10 && 10<=s){
		printf("%d:0%d:%d",h,m,s);
	}
	else if(10<=h && 10<=m && s<10){
		printf("%d:%d:0%d",h,m,s);
	}
	else if(h<10 && m<10 && 10<=s){
		printf("0%d:0%d:%d",h,m,s);
	}
	else if(h<10 && 10<=m && s<10){
		printf("0%d:%d:0%d",h,m,s);
	}
	else if(10<=h && m<10 && s<10){
		printf("%d:0%d:0%d",h,m,s);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^