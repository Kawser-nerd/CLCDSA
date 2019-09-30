#include <string.h>
#include <stdio.h>

int main()
{   char s[21],cstart[13]={"WBWBWWBWBWBW"},dstart[13]={"WBWWBWBWBWWB"},
estart[13]={"WWBWBWBWWBWB"},fstart[13]={"WBWBWBWWBWBW"},gstart[13]={"WBWBWWBWBWWB"},
astart[13]={"WBWWBWBWWBWB"},hstart[13]={"WWBWBWWBWBWB"};
    scanf("%s",s);
    if(strncmp(s,cstart,12)==0){
        printf("Do");
    }
    if(strncmp(s,dstart,12)==0){
        printf("Re");
    }
    if(strncmp(s,estart,12)==0){
        printf("Mi");
    }
    if(strncmp(s,fstart,12)==0){
        printf("Fa");
    }
    if(strncmp(s,gstart,12)==0){
        printf("So");
    }
    if(strncmp(s,astart,12)==0){
        printf("La");
    }
    if(strncmp(s,hstart,12)==0){
        printf("Si");
    }
    

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^