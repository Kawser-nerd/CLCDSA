#include <stdio.h>

int main(void){
    // Your code here!
    
    char s[110];
    float k;
    scanf("%s",s); 
    scanf("%f",&k);
    
    
    int i;
    char ans='1';
    
    for(i=0; i<k; ++i ){
        if( s[i] != ans ){
            ans=s[i];
            break;
        }
    }
    
    
    
    printf("%c",ans);
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s); 
     ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%f",&k);
     ^