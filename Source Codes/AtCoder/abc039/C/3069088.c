#include <stdio.h>

char S[25];
char tmp[13]="WBWBWWBWBWBW";

int main() {

	scanf("%s",S);

	int i,j;

	for(i=0;i<12;i++){
		if(tmp[i]=='W'){
			int flag=0;
			for(j=0;j<20;j++){
				if(tmp[(i+j)%12]!=S[j]){flag=1;}
			}
			if(flag==0){
				if(i==0){printf("Do\n");}
				else if(i==2){printf("Re\n");}
				else if(i==4){printf("Mi\n");}
				else if(i==5){printf("Fa\n");}
				else if(i==7){printf("So\n");}
				else if(i==9){printf("La\n");}
				else if(i==11){printf("Si\n");}
				return 0;
			}
		}
	}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",S);
  ^