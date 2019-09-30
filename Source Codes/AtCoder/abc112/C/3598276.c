#include<stdio.h>
#include<stdlib.h>

int distance(short ax, short ay, short bx, short by);

short X[100];
short Y[100];
int H[100];

int main(){
	short N, i;
	short is;
	if(scanf("%hd", &N));
	short A = -1;
	for(i=0; i<N; i++){
	if(scanf("%hd%hd%d", &X[i], &Y[i], &H[i]));
		if(A==-1 && H[i]!=0){A=i;}
	}
	short CX=0, CY=0;
	int CH=0;
	for(CX=0; CX<=100; CX++){
		for(CY=0; CY<=100; CY++){
			CH = H[A]+distance(CX, CY, X[A], Y[A]);
			is = 1;
			for(i=0; i<N; i++){
				if(H[i] == 0){
					if(distance(CX, CY, X[i], Y[i]) < CH){
						is = 0;
						break;
					}
				}else{
					if(H[i]+distance(CX, CY, X[i], Y[i]) != CH){
						is = 0;
						break;
					}
				}
			}
			if(is){break;}
		}
		if(is){break;}
	}
	printf("%d %d %d\n", CX, CY, CH);
	return 0;
}

int distance(short ax, short ay, short bx, short by){
	return (ax>bx?ax-bx:bx-ax)+(ay>by?ay-by:by-ay);
}