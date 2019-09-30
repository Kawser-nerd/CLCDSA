#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare_char(const void *a, const void *b){
    return strcmp(( char * )a , ( char * )b );
}

int main(void){
    char s[100],t[100];
    int slen,tlen,i,j;
    scanf("%s",s);
    scanf("%s",t);
    slen = strlen(s);
    tlen = strlen(t);
    qsort(s,slen,sizeof(char),compare_char);
    qsort(t,tlen,sizeof(char),compare_char);
    for(i=0,j=tlen-1;i<slen&&j>=0;i++,j--){
        if(s[i]!=t[j]){
             if(s[i]<t[j]){
                printf("Yes\n");
                return 0;
            }else{
                printf("No\n");
                return 0;
            }
        }
    }
    if(slen<tlen){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",t);
     ^