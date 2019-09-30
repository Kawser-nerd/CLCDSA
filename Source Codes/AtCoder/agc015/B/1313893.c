#include <stdio.h>
#include <string.h>

int main(void){
    char s[100000];
    unsigned long long int sum = 0;
    int i;
    int size;
    
    scanf("%s", s);
    
    size = strlen(s);
    
    for( i = 0; i < size; ++i){
        if( s[i] == 'U'){
            sum += (unsigned long long int)(size - (i+1) + i*2) ;
        }else{
            sum += (unsigned long long int)((size- (i+1) )*2 + i);
        }
    }
    printf("%llu\n", sum);
    
    return 0;
    
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s);
     ^