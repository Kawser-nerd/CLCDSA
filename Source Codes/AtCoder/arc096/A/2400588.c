#include <stdio.h>

int ans1(int a, int b, int x, int y){
    return a*x + b*y;
}

int ans2(int a, int b, int c, int x, int y){
    if (x >y)
        return 2*y*c + (x - y)*a;
    else
        return 2*x*c + (y - x)*b;
}

int ans3(int c, int x, int y){
    if (x >y)
        return 2*x*c;
    else
        return 2*y*c;
}

int main(void){
    int a, b, c, x, y;
    int anser1, anser2, anser3, true_ans;
    
    /* input */
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &x);
    scanf("%d", &y);
    
    anser1 = ans1(a, b, x, y);
    anser2 = ans2(a, b, c, x, y);
    anser3 = ans3(c, x, y);
    
    if (anser1 < anser2 && anser1 < anser3){
        true_ans = anser1;
    }
    else if (anser2 < anser3 && anser2 < anser1){
        true_ans = anser2;
    }
    else {
        true_ans = anser3;
    }
    
    /* output */
    printf("%d \n", true_ans);
        
    return 0;
    } ./Main.c: In function ‘main’:
./Main.c:26:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &a);
     ^
./Main.c:27:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &b);
     ^
./Main.c:28:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &c);
     ^
./Main.c:29:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &x);
     ^
./Main.c:30:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &y);
     ^