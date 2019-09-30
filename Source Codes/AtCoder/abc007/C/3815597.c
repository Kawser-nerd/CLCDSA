#include<stdio.h>
#define QL 2500
short Ql=0, Qr=0;
short Q[QL][2], qx, qy;
void push(int x, int y){Q[Qr][0]=x; Q[Qr][1]=y; ++Qr;}
void pop(){qx=Q[Ql][0]; qy=Q[Ql][1]; ++Ql;}
int isempty(){return (Ql==Qr);}

short W, H, Sx, Sy, Gx, Gy, i, j;
short B[50][50];
short MAX=8192;
int main(){
	scanf("%hd %hd\n", &W, &H);
	scanf("%hd %hd\n", &Sx, &Sy); --Sx; --Sy;
	scanf("%hd %hd\n", &Gx, &Gy); --Gx; --Gy;
	for(i=0; i<W; ++i){
		for(j=0; j<H; ++j){
			if(getchar()=='#'){
				B[i][j]=0;
			}else{
				B[i][j]=MAX;
			}
		}
		getchar();
	}
	B[Sx][Sy]=0; push(Sx, Sy);
	while(!isempty()){
		pop();
		if(qx==Gx && qy==Gy){break;}
		if(B[qx-1][qy]==MAX){B[qx-1][qy]=B[qx][qy]+1; push(qx-1, qy);}
		if(B[qx+1][qy]==MAX){B[qx+1][qy]=B[qx][qy]+1; push(qx+1, qy);}
		if(B[qx][qy-1]==MAX){B[qx][qy-1]=B[qx][qy]+1; push(qx, qy-1);}
		if(B[qx][qy+1]==MAX){B[qx][qy+1]=B[qx][qy]+1; push(qx, qy+1);}
	}
	printf("%d\n", B[qx][qy]);
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%hd %hd\n", &W, &H);
  ^
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%hd %hd\n", &Sx, &Sy); --Sx; --Sy;
  ^
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%hd %hd\n", &Gx, &Gy); --Gx; --Gy;
  ^