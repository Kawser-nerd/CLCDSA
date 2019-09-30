#include <stdio.h>

int main(int argc, char** argv)
{
	int a,b;
	int h,w;
	char field[100][101]={0};
	char cha, chb;
	int i,j,k;
	
	scanf("%d%d", &a, &b);
	
	if( a <= b ){
		cha = '.';
		chb = '#';
	} else {
		cha = '#';
		chb = '.';
		a = a - b;
		b = a + b;
		a = b - a;
	}
	
	if( b < 25 ){
		h = 4; w = b * 4;
	} else {
		h = ((b + 24) / 25)*4; w = 100;
	}
	
	for(j=0;j<h;++j)
		for(k=0;k<w;++k)
			field[j][k] = cha;
	
	for(i=0; i<b; ++i){
		for(j=0; j<3; ++j)
			for(k=0; k<3; ++k)
				field[(i/25)*4 + j][(i%25)*4 + k] = chb;
	}
	
	for(i=0; i<a-1; ++i){
		field[(i/25)*4 + 1][(i%25)*4 + 1] = cha;
	}
	
	printf("%d %d\n", h, w);
	for(i=0;i<h;++i){
		printf("%s\n", field[i]);
	}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &a, &b);
  ^