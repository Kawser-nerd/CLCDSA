#include <stdio.h>

typedef unsigned long ulong;

static inline ulong diff(ulong a, ulong b){
    return __builtin_ctzl(a^b);
}
/*
static inline void pl(long n){
#define L 8
    char c[L];
    long i=L-1;
    do{
        c[i]=n%10+'0';
        n/=10;
        i--;
    }while(n>0);
    for(i++;i<L;i++){
        putchar_unlocked(c[i]);
    }
}

static inline void puts_unlocked(const char *s){
    for(size_t i=0; s[i]!='\0'; i++){
        putchar_unlocked(s[i]);
    }
    putchar_unlocked('\n');
}
*/
#define N 17
long data[1<<N];
char buf[819200];
size_t point=0;

static inline void pc(char c){
    buf[point] = c;
    point++;
}
static inline void pl(long n){
#define L 8
    char c[L];
    long i=L-1;
    do{
        c[i]=n%10+'0';
        n/=10;
        i--;
    }while(n>0);
    for(i++;i<L;i++){
        pc(c[i]);
    }
}

static inline void puts_unlocked(const char *s){
    for(size_t i=0; s[i]!='\0'; i++){
        pc(s[i]);
    }
    pc('\n');
}


static void solve(long a, long b, const size_t sp, const size_t ep, long mask){
    if(ep-sp<=2){
        data[sp+0] = a;
        data[sp+1] = b;
        return;
    }
    const ulong d = diff(a, b);
    mask ^= (1<<d);
    const ulong ad = a&(1<<d);
    const ulong bd = b&(1<<d);
    a &= mask;
    b &= mask;
    const ulong ab = a ^ (mask&(-mask));
    const size_t mp = (sp+ep)/2;
    //printf("%ld %ld %ld\n", aa, ab, bb);
    solve(a, ab, sp, mp, mask);
    solve(ab, b, mp, ep, mask);
    for(size_t i=sp; i<mp; i++){ data[i] |= ad; }
    for(size_t i=mp; i<ep; i++){ data[i] |= bd; }
}

int main(void){
    long n, a, b;
    scanf("%ld %ld %ld", &n, &a, &b);
    if(__builtin_popcountl(a)%2 == __builtin_popcountl(b)%2){
        puts("NO");
        return 0;
    }
    solve(a, b, 0, 1<<n, 0xFFFFFFFFFFFFFFFF);
    const size_t m = 1<<n;

    puts_unlocked("YES");
    for(size_t i=0; i<m-1; i++){
        pl(data[i]);
        pc(' ');
    }
    pl(data[m-1]);
    pc('\n');
    fwrite(buf, sizeof(char), point, stdout);
    return 0;
} ./Main.c:53:20: warning: conflicting types for built-in function ‘puts_unlocked’
 static inline void puts_unlocked(const char *s){
                    ^
./Main.c: In function ‘main’:
./Main.c:84:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld %ld %ld", &n, &a, &b);
     ^