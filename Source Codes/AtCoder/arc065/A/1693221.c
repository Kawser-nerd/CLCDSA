#include<stdio.h>
#include<string.h>

int main(){
    int i,j,l,dl,f=1,t;
    char s[131072];
    char d[4][8]={"remaerd","maerd","esare","resare"};
    scanf("%s\n",s);
    l = strlen(s);
    while(f){
        f = 0;
        for(i = 0;i < 4;i++){
            dl = strlen(d[i]);
            for(j = l-1;j > l-1-dl;j--){
                t = l-1-j;
                if(j < 0){break;}
                if(d[i][t] != s[j]){break;}
                if(j == l-dl){f=1;break;}
            }
            if(f){
                if(i == 0){l-=7;}
                if(i == 1){l-=5;}
                if(i == 2){l-=5;}
                if(i == 3){l-=6;}
                break;
            }
        }
        if(l == 0){printf("YES\n");return 0;}
    }
    printf("NO\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s\n",s);
     ^