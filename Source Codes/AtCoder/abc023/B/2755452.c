#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(void){
    int n ;
    char s[120] ;
    scanf ("%d%s",&n,s) ;
    if (n%2==0){
        printf ("-1\n") ;
        exit (0) ;
    }
    if (n%3==0){
        for (int i=0; i<n; i++){
            if (i%3==0 && s[i]=='a'){
                
            } else if (i%3==1 && s[i]=='b'){
                
            } else if (i%3==2 && s[i]=='c'){
                
            } else {
                printf ("-1\n") ;
                exit (0) ;
            }
        }
    } else if (n%3==2){
        for (int i=0; i<n; i++){
            if (i%3==0 && s[i]=='c'){
                
            } else if (i%3==1 && s[i]=='a'){
                
            } else if (i%3==2 && s[i]=='b'){
                
            } else {
                printf ("-1\n") ;
                exit (0) ;
            }
        }
    } else {
        for (int i=0; i<n; i++){
            if (i%3==0 && s[i]=='b'){
                
            } else if (i%3==1 && s[i]=='c'){
                
            } else if (i%3==2 && s[i]=='a'){
                
            } else {
                printf ("-1\n") ;
                exit (0) ;
            }
        }
    }
    printf ("%d\n",(n-1)/2) ;
    return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf ("%d%s",&n,s) ;
     ^