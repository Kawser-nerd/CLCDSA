#include <stdio.h>
#define L 6
char c[L];
inline void pl(int a){
    register long i=L-2;
    do{ c[i]=a%10+48; a/=10; i--; }while(a>0);
    stdout->_IO_write_ptr += L-1-i;
    char* p = stdout->_IO_write_ptr;
    do{ ++i; p[i-L] = c[i]; }while(i<L-1);
}

static void solve(const int n, const int a, const int b, int mask, const int common){
    const int t = a^b;
    const int d = t&(-t);
    mask ^= d;
    const int aa = a & mask, ab = aa ^ (mask&(-mask));
    if(n==2){
        if(__builtin_expect(stdout->_IO_write_ptr+4*L >= stdout->_IO_write_end,0)){
            fflush_unlocked(stdout);
        }
        pl(common|a);
        pl(common|ab|(a&d));
        pl(common|ab|(b&d));
        pl(common|b);
    }else{
        solve(n-1, aa, ab, mask, common|(a&d));
        solve(n-1, ab, b&mask, mask, common|(b&d));
    }
}

int main(void){
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    if(__builtin_expect(__builtin_parity(a)==__builtin_parity(b),0)){
        puts("NO");
    }else{
        puts("YES");
        if(__builtin_expect(n==1,0)){
            printf("%d %d\n", a, b);
        }else{
            c[L-1]=' ';
            solve(n, a, b, -1, 0);
        }
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:33:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d", &n, &a, &b);
     ^