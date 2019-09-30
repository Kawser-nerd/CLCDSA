#include <stdio.h>

int main(void)
{
   int N;
   int F[100][11];
   int P[100][12];
      int C[11];
      C[0]=11;
   scanf("%d",&N);
   int n;
   for(n=0;n<N;n++){
   	int x;
   	for(x=1;x<=10;x++){
   		scanf("%d",&F[n][x]);
   		if(F[n][x]==1){
   			C[x]++;
   		}
   	}
   }

   for(n=0;n<N;n++){
   	int x;
   	for(x=0;x<11;x++){
   		scanf("%d",&P[n][x]);
//printf("%d\n",C[x]);
   	}

   }
   
   int a,b,c,d,e,f,g,h,i,j,flag=0;
   int max=-1000000000;
   for(a=0;a<2;a++){
   	for(b=0;b<3;b+=2){
   		for(c=0;c<4;c+=3){
   			for(d=0;d<5;d+=4){
   				for(e=0;e<6;e+=5){
   					for(f=0;f<7;f+=6){
   						for(g=0;g<8;g+=7){
   							for(h=0;h<9;h+=8){
   								for(i=0;i<10;i+=9){
   									for(j=0;j<11;j+=10){
   										if(flag==0){flag=1;continue;}
   										int min=0;								for(n=0;n<N;n++){
   											
int p=F[n][a]+F[n][b]+F[n][c]+F[n][d]+F[n][e]+F[n][f]+F[n][g]+F[n][h]+F[n][i]+F[n][j];
   											min+=P[n][p];
   										}
   									if(min>max){max=min;}
   									}
   								}
   							}
   						}
   					}
   				}
   			}
   		}
   	}
   }
   
   printf("%d\n",max);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&N);
    ^
./Main.c:15:6: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
      scanf("%d",&F[n][x]);
      ^
./Main.c:25:6: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
      scanf("%d",&P[n][x]);
      ^