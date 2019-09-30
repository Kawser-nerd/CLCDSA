#include <stdio.h>
#include <string.h>

char Sa[100],Sb[100],Sc[100];
int cnta = 0,cntb = 0,cntc =0;
int lena,lenb,lenc;
int turna(){
	if(cnta == lena ){
		return 1;
	}
	if(Sa[cnta] == 'a'){
		cnta++;
		return turna();
	}else if(Sa[cnta] == 'b'){
		cnta++;
		return turnb();
	}else if(Sa[cnta] == 'c'){
		cnta++;
		return turnc();
	}
		
}
int turnb(){
	if(cntb == lenb){
		return 2;
	}
	if(Sb[cntb] == 'a'){
		cntb++;
		return turna();
	}else if(Sb[cntb] == 'b'){
		cntb++;
		return turnb();
	}else if(Sb[cntb] == 'c'){
		cntb++;
		return turnc();
	}
}
int turnc(){
	if(cntc == lenc){
		return 3;
	}
	if(Sc[cntc] == 'a'){
		cntc++;
		return turna();
	}else if(Sc[cntc] == 'b'){
		cntc++;
		return turnb();
	}else if(Sc[cntc] == 'c'){
		cntc++;
		return turnc();
	}
}
int main(){
	scanf("%s %s %s",Sa,Sb,Sc);
	lena = strlen(Sa);
	lenb = strlen(Sb);
	lenc = strlen(Sc);
	int ret = turna();
	if(ret == 1){
		printf("A\n");
	}else if(ret == 2){
		printf("B\n");
	}else if(ret == 3){
		printf("C\n");
	}
} ./Main.c: In function ‘turna’:
./Main.c:16:10: warning: implicit declaration of function ‘turnb’ [-Wimplicit-function-declaration]
   return turnb();
          ^
./Main.c:19:10: warning: implicit declaration of function ‘turnc’ [-Wimplicit-function-declaration]
   return turnc();
          ^
./Main.c: In function ‘main’:
./Main.c:54:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s %s %s",Sa,Sb,Sc);
  ^