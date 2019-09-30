#include <stdio.h>
#include <string.h>

int main(){
    char S[12];
    fgets(S,sizeof(S),stdin);
    S[strlen(S)-1]='\0';
    fflush(stdin);
    int cnt=0;
    int cnt_max=0;
    for(int i; i<11; i++){
        if(S[i]=='A' || S[i]=='C' || S[i]=='G' || S[i]=='T'){
            cnt++;
        }else if(cnt>cnt_max){
            cnt_max=cnt;
            cnt=0;
        }else{
            cnt=0;
        }
    }
    printf("%d\n", cnt_max);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
     fgets(S,sizeof(S),stdin);
     ^