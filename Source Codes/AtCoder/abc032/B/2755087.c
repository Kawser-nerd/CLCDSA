#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
    char s[320] ;
    int k,ans=0 ;
    scanf ("%s%d",s,&k) ;
    char key[strlen(s)+10][k+10] ;
    if (strlen(s)<k){
        printf ("0\n") ;
        exit (0) ;
    }
    for (int i=0; i<strlen(s)-k+1; i++){
        strncpy(key[i],s+i,k);
        key[i][k]='\0' ;
        int count=0 ;
        for (int j=0; j<=i; j++){
            if(strcmp(key[i],key[j])==0){
                break ;
            } else {
                count++ ;
                if (count>=i){
                    ans++ ;
                }
            }
        }
    }
    printf ("%d\n",ans+1) ;
    return 0 ;   
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf ("%s%d",s,&k) ;
     ^