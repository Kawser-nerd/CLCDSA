#include<stdio.h>
#include<string.h>

int sis(float a){
	int i=a;
	if(i%10<=4)return i-i%10;
	else return i-i%10+10;
}

int main(){
	int n,m,dis;
	double deg,di,ho=11.25;
	scanf("%d%d",&n,&m);
	deg=n/(double)10;
	di=m/(double)60;
	char ans[4]={0};
	int huso=0,ens;
	int hou=deg/ho;
	dis=sis(di*100);
	if(hou== 0||hou==31)strcpy(ans,"N");
	if(hou== 1||hou== 2)strcpy(ans,"NNE");
	if(hou== 3||hou== 4)strcpy(ans,"NE");
	if(hou== 5||hou== 6)strcpy(ans,"ENE");
	if(hou== 7||hou== 8)strcpy(ans,"E");
	if(hou== 9||hou==10)strcpy(ans,"ESE");
	if(hou==11||hou==12)strcpy(ans,"SE");
	if(hou==13||hou==14)strcpy(ans,"SSE");
	if(hou==15||hou==16)strcpy(ans,"S");
	if(hou==17||hou==18)strcpy(ans,"SSW");
	if(hou==19||hou==20)strcpy(ans,"SW");
	if(hou==21||hou==22)strcpy(ans,"WSW");
	if(hou==23||hou==24)strcpy(ans,"W");
	if(hou==25||hou==26)strcpy(ans,"WNW");
	if(hou==27||hou==28)strcpy(ans,"NW");
	if(hou==29||hou==30)strcpy(ans,"NNW");
	if(dis<=20)ens=0;
	if(30<=dis&&dis<=150)ens=1;
	if(160<=dis&&dis<=330)ens=2;
	if(340<=dis&&dis<=540)ens=3;
	if(550<=dis&&dis<=790)ens=4;
	if(800<=dis&&dis<=1070)ens=5;
	if(1080<=dis&&dis<=1380)ens=6;
	if(1390<=dis&&dis<=1710)ens=7;
	if(1720<=dis&&dis<=2070)ens=8;
	if(2080<=dis&&dis<=2440)ens=9;
	if(2450<=dis&&dis<=2840)ens=10;
	if(2850<=dis&&dis<=3260)ens=11;
	if(3270<=dis)ens=12;
	if(ens==0)strcpy(ans,"C");
	printf("%s %d\n",ans,ens);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&m);
  ^