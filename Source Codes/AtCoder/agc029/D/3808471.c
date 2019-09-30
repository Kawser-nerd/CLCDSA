#include <stdio.h>
typedef unsigned int uint;

#pragma GCC optimize ("O3")
inline static uint gl(void){
    uint x = 0;
    for(;;){
        const uint c = getchar_unlocked() - 48;
        if(c < 10){
            x = x*10 + c;
        }else{
            break;
        }
    }
    return x;
}
#pragma GCC optimize ("Ofast")
#define H 200000
uint v[H] __attribute__((aligned(64)));
int main(void){
    const uint h = gl();
    gl();
    const uint n = gl();
    for(uint i=0; i<H; i++){ v[i] = 0xffffff; }
    for(uint i=0; i<n; i++){
        const uint x = gl()-1;
        const uint y = gl()-1;
        v[x] = y<v[x] ? y : v[x];
    }
    uint right = 0;
    for(uint x=1; x<h; x++){
        const auto b = v[x];
        const auto r = right+1;
        if(b<r){
            printf("%d\n", x);
            return 0;
        }else if(b>r){
            right=r;
        }
    }
    printf("%d\n", h);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:32:20: warning: type defaults to ‘int’ in declaration of ‘b’ [-Wimplicit-int]
         const auto b = v[x];
                    ^
./Main.c:33:20: warning: type defaults to ‘int’ in declaration of ‘r’ [-Wimplicit-int]
         const auto r = right+1;
                    ^