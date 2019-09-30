#include <stdio.h>
int main(void){
	double Deg,Dis;
	double ws;
	scanf("%lf %lf",&Deg,&Dis);
	
	ws = Dis / 60;

	if(ws >= 0 && ws <0.25){
		printf("C ");
	}else if(Deg >= 112.5 && Deg < 337.5){
		printf("NNE ");
	}else if(Deg >= 337.5 && Deg < 562.5){
		printf("NE ");
	}else if(Deg >= 562.5 && Deg < 787.5){
		printf("ENE ");
	}else if(Deg >= 787.5 && Deg < 1012.5){
		printf("E ");
	}else if(Deg >= 1012.5 && Deg < 1237.5){
		printf("ESE ");
	}else if(Deg >= 1237.5 && Deg < 1462.5){
		printf("SE ");
	}else if(Deg >= 1462.5 && Deg < 1687.5){
		printf("SSE ");
	}else if(Deg >= 1687.5 && Deg < 1912.5){
		printf("S ");
	}else if(Deg >= 1912.5 && Deg < 2137.5){
		printf("SSW ");
	}else if(Deg >= 2137.5 && Deg < 2362.5){
		printf("SW ");
	}else if(Deg >= 2362.5 && Deg < 2587.5){
		printf("WSW ");
	}else if(Deg >= 2587.5 && Deg < 2812.5){
		printf("W ");
	}else if(Deg >= 2812.5 && Deg < 3037.5){
		printf("WNW ");
	}else if(Deg >= 3037.5 && Deg < 3262.5){
		printf("NW ");
	}else if(Deg >= 3262.5 && Deg < 3487.5){
		printf("NNW ");
	}else{
		printf("N ");
	}


	if(ws >= 0 && ws <0.25){
		printf("0\n");
	}else if(ws >= 0.25 && ws < 1.55){
		printf("1\n");
	}else if(ws >= 1.55 && ws < 3.35){
		printf("2\n");
	}else if(ws >= 3.35 && ws < 5.45){
		printf("3\n");
	}else if(ws >= 5.45 && ws < 7.95){
		printf("4\n");
	}else if(ws >= 7.95 && ws < 10.75){
		printf("5\n");
	}else if(ws >= 10.75 && ws < 13.85){
		printf("6\n");
	}else if(ws >= 13.85 && ws < 17.15){
		printf("7\n");
	}else if(ws >= 17.15 && ws < 20.75){
		printf("8\n");
	}else if(ws >= 20.75 && ws < 24.45){
		printf("9\n");
	}else if(ws >= 24.45 && ws < 28.45){
		printf("10\n");
	}else if(ws >= 28.45 && ws < 32.65){
		printf("11\n");
	}else if(ws >= 32.65){
		printf("12\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lf %lf",&Deg,&Dis);
  ^