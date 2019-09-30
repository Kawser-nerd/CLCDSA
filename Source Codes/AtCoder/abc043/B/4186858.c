#include <stdio.h>
int main(void){
    char key[11];
    char out[11];
    for(int i=0;i<11;i++)
    {
        key[i] = out[i] = 0;    
    }
    gets(key);
    int i=0,j=0;
    while(1)
    {
        switch(key[i])
        {
            case '0':
                out[j] = '0';
                j++;
                break;
            
            case '1':
                out[j] = '1';
                j++;
                break;
                
            case 'B':
                if(j>0)
                {
                    out[--j] = 0;
                }
                break;
                
            default:
                puts(out);
                return 0;
        }
        i++;
    }
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
     gets(key);
     ^
/tmp/cc5v3kSP.o: In function `main':
Main.c:(.text.startup+0x31): warning: the `gets' function is dangerous and should not be used.