#include <stdio.h>
#include<string.h>
int main(void){
    char anus[114];
    scanf("%s",anus);
    int ans=100000;
  int sex = strlen( anus);
    for(int i=0;i<26;i++){
        int kari=-1;
        int karians=100000;
        for(int j=0;j<sex;j++){
            if(anus[j]==(char)'a'+i){
                if(kari==-1)karians=j;
                else if(karians<j-kari-1)karians=j-kari-1;
                kari=j;
            }
            if(j==sex-1)if(karians<(sex-1-kari))karians=sex-1-kari;
        }
        if(ans>karians){ans=karians;}
    }
    printf("%d",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",anus);
     ^