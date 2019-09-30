#include<stdio.h>
long unsigned int diff(long unsigned int a, long unsigned int b, long unsigned int c) {
    long unsigned int max=a,min=a;
    if(max < b) {
        max = b;
    }
    if(max < c) {
        max = c;
    }
    if(min > b) {
        min = b;
    }
    if(min > c) {
        min = c;
    }
    return max - min;
}

long unsigned int main(void) {
    long unsigned int h,w;
    long unsigned int i;
    long unsigned int a,b,c;
    scanf("%lu%lu",&h,&w);
    long unsigned int min = h*w;
    long unsigned int area = h*w;
    if (h%3==0 || w%3==0) {
        printf("0\n");
        return 0;
    }
    for (i=0; i<h/2; i++) {
        a = (h/2-i)*w;
        b = (w/2)*(h-(h/2-i));
        c = area - a - b;
        if(min > diff(a,b,c)) {
            min = diff(a,b,c);
        }
    }
    long unsigned int memo = h;
    h = w;
    w = memo;
    for (i=0; i<h/2; i++) {
        a = (h/2-i)*w;
        b = (w/2)*(h-(h/2-i));
        c = area - a - b;
        if(min > diff(a,b,c)) {
            min = diff(a,b,c);
        }
    }
    if(min > h) {
        min = h;
    }
    if(min > w) {
        min = w;
    }
    printf("%lu\n", min);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:23:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lu%lu",&h,&w);
     ^