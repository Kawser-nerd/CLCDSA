#include <stdio.h>

int pattern(int x)
{
	if(x==0) return 1;
	if(x==1) return 2;
	if(x==2) return 3;
	if(x==3) return 5;
	if(x==4) return 8;
	if(x==5) return 13;
	if(x==6) return 21;
	if(x<0||x>6) return 1;
	
	printf("error");
	return 0;
}

int main(void)
{
	//?????
	int h,w,k;
	long int now[10];
	//int?????????????long???
	long int kako[10];
	int left,right;
	int i,j;
	
	
	//????????
	scanf("%d %d %d",&h,&w,&k);
//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	
	for(j=0;j<10;j++){
		kako[j]=0;
	}
	kako[0]=1;
	
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			left=j-1;
			right=w-j-2;
			now[j]=kako[j]*pattern(left)*pattern(right);
			if(j!=0) now[j]=now[j]+kako[j-1]*pattern(left-1)*pattern(right);
			if(j!=w) now[j]=now[j]+kako[j+1]*pattern(left)*pattern(right-1);
		}
		for(j=0;j<w;j++){
			kako[j]=(now[j]%1000000007);
		}
		
//		printf("%d??",i);
		for(j=0;j<w;j++){
//			printf("now[%d]=%ld",j,kako[j]);
		}
//		printf("\n");
	}
	
//	printf("??????\n");
	
	//??
	
	printf("%d",kako[k-1]);
	
//	printf("???????\n");
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:63:9: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long int’ [-Wformat=]
  printf("%d",kako[k-1]);
         ^
./Main.c:30:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d",&h,&w,&k);
  ^