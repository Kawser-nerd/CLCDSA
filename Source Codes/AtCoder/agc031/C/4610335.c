#include <stdio.h>

char c[7]={32,32,32,32,32,32,32};
inline void pl(int n){
    int i=5;
    do{ c[i]=n%10+48; n/=10; i--; }while(n>0);
    if(stdout->_IO_write_ptr+7 >= stdout->_IO_write_end){
        fflush_unlocked(stdout);
    }
    for(i++;i<7;i++){
        *stdout->_IO_write_ptr++ = c[i];
        //putchar_unlocked(c[i]);
    }
}

static void solve(const int n, const int a, const int b, int mask, const int common){
    if(n==1){
        pl(common|a);
        pl(common|b);
    }else{
        const int t = a^b;
        const int d = t&(-t);
        mask ^= d;
        const int aa = a & mask, ab = aa ^ (mask&(-mask));
        solve(n-1, aa, ab, mask, common|(a&d));
        solve(n-1, ab, b&mask, mask, common|(b&d));
    }
}

int main(void){
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    if(__builtin_parity(a)==__builtin_parity(b)){
        puts("NO");
    }else{
        puts("YES");
        solve(n, a, b, -1, 0);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:32:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d", &n, &a, &b);
     ^