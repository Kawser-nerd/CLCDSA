#include <stdio.h>
#include <stdlib.h>

int price,disnumber,answer,test_n;
char str[6];
int dislike [9];

int testing (void){//if???????
    int i,j;
    int use_dis = 0;
    for (i=6;i>=0;i--){
        test_n = str[i]-'0';
        for (j=0;j<disnumber;j++){
            if (test_n == dislike[j]){
                use_dis++;
                break;
            }
        }
    }
    if (use_dis){return 0;}
    else {return 1;}
}

int main (void){
//????
    int a;
    scanf("%d %d",&price ,&disnumber);
    for(a=0;a< disnumber;a++){
        scanf("%d",&dislike[a]);
    }
//????
    answer = price;
    sprintf (str,"%d",answer);
    while(1){
        if(testing()){
            printf("%d\n",answer);
            break;
        }else{
            answer++;
            sprintf (str,"%d",answer);
        }
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:27:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&price ,&disnumber);
     ^
./Main.c:29:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&dislike[a]);
         ^