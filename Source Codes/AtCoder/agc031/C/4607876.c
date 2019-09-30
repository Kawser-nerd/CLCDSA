#include <stdio.h>
#define L 6
#define putlong_unlocked(X) \
    do{ \
        long n=X; \
        char c[L]; \
        long i=L-1; \
        do{ c[i]=n%10+'0'; n/=10; i--; }while(n>0); \
        for(i++;i<L;i++){ putchar_unlocked(c[i]); } \
    }while(0)
#define puts_unlocked(X) \
    do { \
        for(size_t i=0; X[i]!='\0'; i++){ \
            putchar_unlocked(X[i]); \
        } \
        putchar_unlocked('\n'); \
    }while(0)

static void solve(const long n, const long a, const long b, long mask, const long common){
    if(n==1){
        putlong_unlocked(common|a);
        putchar_unlocked(' ');
        putlong_unlocked(common|b);
        putchar_unlocked(' ');
    }else{
        const long t = a^b;
        const long d = t&(-t);
        mask ^= d;
        const long aa = a & mask;
        const long ab = aa ^ (mask&(-mask));
        solve(n-1, aa,     ab, mask, common|(a&d));
        solve(n-1, ab, b&mask, mask, common|(b&d));
    }
}

int main(void){
    long n, a, b;
    scanf("%ld %ld %ld", &n, &a, &b);
    if(__builtin_parity(a) == __builtin_parity(b)){
        puts_unlocked("NO");
    }else{
        puts_unlocked("YES");
        solve(n, a, b, 0xFFFFFFFFFFFFFFFF, 0);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:38:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld %ld %ld", &n, &a, &b);
     ^