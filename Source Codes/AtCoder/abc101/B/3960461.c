#include<stdio.h>
#include<stdlib.h>

int getLength(char a[]);

int main(void){
    int i,len,sum=0;
    char num[15];
    gets(num);
    len=getLength(num);
    for(i=0;i<len;i++){
        sum+=num[i]-'0';    
    }
    if(atoi(num)%sum){
        puts("No");
        return 0;
    }else{
        puts("Yes");
        return 0;
    }
    
    return 0;
}
    
int getLength(char a[]){
    int i=0;
    while(a[i]){
        i++;
    }
    return i;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
     gets(num);
     ^
/tmp/ccMAiY9o.o: In function `main':
Main.c:(.text.startup+0x19): warning: the `gets' function is dangerous and should not be used.