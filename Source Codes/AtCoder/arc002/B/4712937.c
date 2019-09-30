#include<stdio.h>

int main(){
	char s[11];
	int y=0,m=0,d=0,i;
	scanf("%s",s);
	for(i=0;i<4;i++)y=y*10+s[i]-'0';
	for(i=5;i<7;i++)m=m*10+s[i]-'0';
	for(i=8;i<10;i++)d=d*10+s[i]-'0';
//	printf("%d/%02d/%02d\n",y,m,d);
	for(;;y++){
		for(;m<=12;m++){
			for(;;d++){
				if(y/m/d*m*d==y){
					printf("%d/%02d/%02d\n",y,m,d);
					return 0;
				}
				int u=0;
				if(y%400==0)u=1;
				else if(y%100==0);
				else if(y%4==0)u=1;
				if((m==1||m==3||m==5||m==7||m==8||m==10||m==12)&&d>=31)break;
				if((m==4||m==6||m==9||m==11)&&d>=30)break;
				if(u==1&&m==2&&d>=29)break;
				if(u==0&&m==2&&d>=28)break;
			}
			d=1;
		}
		m=1;
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^