#include<stdio.h>
#include<math.h>

int main(){
	double a,b,c,s;
	int xy[3][2];
	scanf("%d%d%d%d%d%d",&xy[0][0],&xy[0][1],&xy[1][0],&xy[1][1],&xy[2][0],&xy[2][1]);
	a=sqrt((xy[0][0]-xy[1][0])*(xy[0][0]-xy[1][0])+(xy[0][1]-xy[1][1])*(xy[0][1]-xy[1][1]));
	b=sqrt((xy[2][0]-xy[1][0])*(xy[2][0]-xy[1][0])+(xy[2][1]-xy[1][1])*(xy[2][1]-xy[1][1]));
	c=sqrt((xy[2][0]-xy[0][0])*(xy[2][0]-xy[0][0])+(xy[2][1]-xy[0][1])*(xy[2][1]-xy[0][1]));
	s=(a+b+c)/2;
	printf("%f\n",sqrt(s*(s-a)*(s-b)*(s-c)));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d%d%d",&xy[0][0],&xy[0][1],&xy[1][0],&xy[1][1],&xy[2][0],&xy[2][1]);
  ^