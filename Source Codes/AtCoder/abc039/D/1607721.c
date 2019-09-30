#include <stdio.h>
#include <string.h>

char po[3][114][114];

int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}

int main(void){
    int H,W;
    scanf("%d %d",&H,&W);
    for(int i=0;i<H;i++)scanf("%s",po[0][i]);
    for(int i=0;i<H;i++)for(int j=0;j<W;j++){
        int flag3=1;
        for(int k=max(0,i-1);k<min(H,i+2);k++)for(int l=max(0,j-1);l<min(W,j+2);l++){
            if(po[0][k][l]=='.')flag3=0;
        }
        if(flag3==1)po[1][i][j]='#';
        else po[1][i][j]='.';
    }
            for(int i=0;i<H;i++)for(int j=0;j<W;j++){
                int flag3=0;
            for(int k=max(0,i-1);k<min(H,i+2);k++)for(int l=max(0,j-1);l<min(W,j+2);l++){
                if(po[1][k][l]=='#')flag3=1;
            }
            if(flag3==1)po[2][i][j]='#';
            else po[2][i][j]='.';
            }
int yamada=0;
for(int i=0;i<H;i++){
    if(strcmp(po[0][i],po[2][i])!=0)yamada=1;
}
if(yamada==1)printf("impossible\n");
else{
    printf("possible\n");
    for(int i=0;i<H;i++)printf("%s\n",po[1][i]);
}
return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&H,&W);
     ^
./Main.c:12:25: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(int i=0;i<H;i++)scanf("%s",po[0][i]);
                         ^