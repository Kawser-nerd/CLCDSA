#include<stdio.h>

int main(){
    int a,b,ans,work,tmp,count=0;

    scanf("%d %d",&a,&b);
    if(a<b){
        tmp = a;
        a = b;
        b = tmp;
    }

    work = a - b;
    while(work>=10){
        if(work>=10){
            work -= 10;
            count++;
        }
    }
    switch(work){
        case 0: break;
        case 1: count++; break;
        case 2: count += 2; break;
        case 3: count += 3; break;
        case 4: count += 2; break;
        case 5: count += 1; break;
        case 6: count += 2; break;
        case 7: count += 3; break;
        case 8: count += 3; break;
        case 9: count += 2; break;
    } 
    printf("%d\n",count);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&a,&b);
     ^