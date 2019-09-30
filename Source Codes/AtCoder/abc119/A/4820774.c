#include<stdio.h>
int main(void){
	char y[10];
	int i,kazu[10],yy,m,d;
	scanf("%s",&y);
	for(i=0;i<10;i++){
		if(i!=4&&i!=7){
			if(y[i]=='0'){
				kazu[i]=0;
			}else if(y[i]=='1'){
				kazu[i]=1;
			}else if(y[i]=='2'){
				kazu[i]=2;
			}else if(y[i]=='3'){
				kazu[i]=3;
			}else if(y[i]=='4'){
				kazu[i]=4;
			}else if(y[i]=='5'){
				kazu[i]=5;
			}else if(y[i]=='6'){
				kazu[i]=6;
			}else if(y[i]=='7'){
				kazu[i]=7;
			}else if(y[i]=='8'){
				kazu[i]=8;
			}else if(y[i]=='9'){
				kazu[i]=9;
			}
		}
	}
	yy=kazu[0]*1000+kazu[1]*100+kazu[2]*10+kazu[3];
	m=kazu[5]*10+kazu[6];
	d=kazu[8]*10+kazu[9];
	
	if(yy>2019){
		printf("TBD\n");
	}else if(yy==2019&&m>4){
		printf("TBD\n");
	}else if(yy==2019&&m==4&&d>30){
		printf("TBD\n");
	}else{
		printf("Heisei\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:8: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[10]’ [-Wformat=]
  scanf("%s",&y);
        ^
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",&y);
  ^