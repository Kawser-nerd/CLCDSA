#include <stdio.h>

inline void gc(long* x){
    *x = 0;
    for(;;){
        int c=getchar_unlocked();
        if('0'<= c && c <='9'){
            *x = *x*10 + c-'0';
        }else{
            break;
        }
    }
}

int main(void){
    long n, count=-1, old=-1, new;
    gc(&n);
    for(long i=0; i<n; i++){
        gc(&new);
        long d = new-old;
        if(d>=2){
            puts("-1");
            return 0;
        }else if(d==1){
            count++;
        }else{
            count += new;
        }
        old = new;
    }
    printf("%ld\n", count);
    return 0;
}