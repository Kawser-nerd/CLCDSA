#include<stdio.h>
#include<string.h>

int main(){
    char s[32];
    scanf("%s",s);
    if(strcmp(s,"WBWBWWBWBWBWWBWBWWBW") == 0){printf("Do\n");}
    if(strcmp(s,"WBWWBWBWBWWBWBWWBWBW") == 0){printf("Re\n");}
    if(strcmp(s,"WWBWBWBWWBWBWWBWBWBW") == 0){printf("Mi\n");}
    if(strcmp(s,"WBWBWBWWBWBWWBWBWBWW") == 0){printf("Fa\n");}
    if(strcmp(s,"WBWBWWBWBWWBWBWBWWBW") == 0){printf("So\n");}
    if(strcmp(s,"WBWWBWBWWBWBWBWWBWBW") == 0){printf("La\n");}
    if(strcmp(s,"WWBWBWWBWBWBWWBWBWWB") == 0){printf("Si\n");}
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^