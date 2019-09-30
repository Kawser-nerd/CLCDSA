#include<stdio.h>

int main(){
	int rec[31]={0,5,27,143,751,935,607,903,991,335,47,
			943,471,55,447,463,991,95,607,263,151,
			855,527,743,351,135,407,903,791,135,647};
	int num,m,n=0;
	scanf("%d",&num);
	while(n<num){
		scanf("%d",&m);
		printf("Case #%d: %03d\n",n+1,rec[m]);
		n++;
	}
	return 0;
}
