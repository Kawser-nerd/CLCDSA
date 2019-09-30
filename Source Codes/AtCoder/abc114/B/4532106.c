#include <stdio.h>

int main(){
    char s[10];scanf("%s",s);
    int i=0;int min=1e3;int abs;
    
    while(s[i+2]!='\0'){
        abs=(int)((s[i]-'0')*100+(s[i+1]-'0')*10+(s[i+2]-'0'));
        if(abs>753){
            abs-=753;
        }else{
            abs=753-abs;
        }   
        if(min>abs){
            min=abs;
        }   
        i++;
    }   
    printf("%d\n",min);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:16: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     char s[10];scanf("%s",s);
                ^