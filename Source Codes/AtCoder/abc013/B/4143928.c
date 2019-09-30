#include <stdio.h>
int main(){
    int a,b,c;
    scanf ("%d",&a);
    scanf ("%d",&b);
    if(a-b>0){   
        c=a-b;
    }else{
        c=b-a;
    }
    if(c>5){           
        c=10-c;
    }   
    printf ("%d\n",c);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf ("%d",&a);
     ^
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf ("%d",&b);
     ^