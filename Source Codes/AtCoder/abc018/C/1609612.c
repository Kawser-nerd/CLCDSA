#include<stdio.h>

int max(int a,int b){if(a>b){return a;}return b;}
int min(int a,int b){if(a<b){return a;}return b;}
int zt(int a,int b){return max(a,b)-min(a,b);}

int main(void){
    int r,c,k,f[512][512]={0},i,j,p,q,res=0;
    char s[512][512];
    scanf("%d%d%d",&r,&c,&k);k--;
    for(i=0;i<r;i++){scanf("%s",s[i]);}
    for(i = 0;i < r;i++){
        for(j = 0;j < c;j++){
            if(s[i][j] == 'o'){continue;}
            for(p = i-k;p <= i+k;p++){
                if(p<0 || p>=r){continue;}
                for(q = j-k;q <= j+k;q++){
                    if(q<0 || q>=c){continue;}
                    if(zt(i,p)+zt(j,q) > k){continue;}
                    f[p][q]=1;
                }
            }
        }
    }
    for(i = k;i < r-k;i++){
        for(j = k;j < c-k;j++){if(f[i][j] == 0){res++;}}
    }
    printf("%d\n",res);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&r,&c,&k);k--;
     ^
./Main.c:11:22: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(i=0;i<r;i++){scanf("%s",s[i]);}
                      ^