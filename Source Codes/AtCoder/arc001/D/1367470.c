#include <stdio.h>

char manko[10];
    int ok[8][8];
    int tate[8]={};
    int yoko[8]={};
    int slash[15]={};
    int backslash[15]={};
    int endflag=0;

void dfs(int queennum){
    for(int i=0;i<8;i++){
        if(endflag==1)break;
        for(int j=0;j<8;j++){
            if(endflag==1)break;
            if(ok[i][j]==0&&tate[i]==0&&yoko[j]==0&&slash[i+j]==0&&backslash[j-i+7]==0&&endflag==0){
                if(queennum==7){ok[i][j]=1;endflag=1;
                    for(int k=0;k<8;k++){for(int l=0;l<8;l++){if(ok[k][l]==1)printf("Q");else printf(".");}printf("\n");}
                }
                else {ok[i][j]=1;tate[i]=1;yoko[j]=1;slash[i+j]=1;backslash[j-i+7]=1;dfs(queennum+1);if(endflag==0){ok[i][j]=0;tate[i]=0;yoko[j]=0;slash[i+j]=0;backslash[j-i+7]=0;}}
            }
        }
    }
}

int main(void){
    
    for(int i=0;i<8;i++){
        scanf("%s",manko);
        for(int j=0;j<8;j++){if(manko[j]=='Q'){ok[i][j]=1;tate[i]++;yoko[j]++;slash[i+j]++;backslash[j-i+7]++;}else ok[i][j]=0;}
    }
    for(int i=0;i<8;i++)for(int j=0;j<8;j++)if((tate[i]>1||yoko[j]>1||slash[i+j]>1||backslash[j-i+7]>1)&&endflag==0){endflag=1;printf("No Answer");}
    if(endflag==0)dfs(3);
    if(endflag==0)printf("No Answer");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:29:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s",manko);
         ^