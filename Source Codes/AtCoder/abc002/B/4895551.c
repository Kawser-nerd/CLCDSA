#include <stdio.h>
#define NUM 30
int main(void){
    
    char c;
    
    while(1)
    {
        c=getchar();
        if(c=='\n')break;
        if(c!='a'&&c!='i'&&c!='u'&&c!='e'&&c!='o')printf("%c", c);
    }

    printf("\n");

    return 0;
}