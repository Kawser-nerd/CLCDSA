#include<stdio.h>

int main(void){
    char l[32];
    char l2[32];
    int a=0;
    scanf("%s",l);

    for(int i=0;i<32;i++){
        if(l[i]=='a'){
            l[i]='0';
        }
        if(l[i]=='i'){
            l[i]='0';
        }
        if(l[i]=='u'){
            l[i]='0';
        }
        if(l[i]=='e'){
            l[i]='0';
        }
        if(l[i]=='o'){
            l[i]='0';
        }      
    }

    for(int j=0;j<32;j++){
        if(l[j]=='0'){
            a++;
            continue;
        }
        else{
            l2[j-a]=l[j];
        }
    }

    printf("%s\n",l2);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",l);
     ^