//O(N^2)
#include <stdio.h>
#include <x86intrin.h>
typedef unsigned int uint;
#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
inline uint read(void){
    _Bool flag = 0;
    uint num = 0;
    for(;;){
        uint c = getchar_unlocked() - 48;
        if(c < 10){
            num = num*10+c;
            flag = 1;
        }else if(flag){
            return num;
        }
    }
}
#define B 1024
#define N (((200000+B-1)/B)*B)
#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
uint input(uint *np, uint *c){
    const uint n = read();
    *np = ((n+B-1)/B)*B;
    if(n&1){
        uint s = 0;
        for(uint i=0; i<n; i++){
            uint t = read();
            s ^= t;
            c[i] = t;
        }
        for(uint i=0; i<n; i++){
            uint t = read();
            s ^= t;
            c[N+i] = t;
        }
        return s;
    }else{
        for(uint i=0; i<n; i++){
            c[i] = read();
        }
        for(uint i=0; i<n; i++){
            c[N+i] = read();
        }
        return 0;
    }
}
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx")
int main(void){
    uint* c = calloc(N, 2*sizeof(uint));
    uint ss[4] __attribute__ ((aligned (16)));
    uint n;
    uint s = input(&n, c);
    __m128i s0 = _mm_setzero_si128();
    __m128i s1 = _mm_setzero_si128();
    __m128i s2 = _mm_setzero_si128();
    __m128i s3 = _mm_setzero_si128();
    for(uint j=0; j<n; j+=B/2){
        for(uint i=0; i<n; i+=B*2){
            __m128i * bb = (__m128i*)(c+N+j);
            for(uint jj=0; jj<B/8; jj++){
                __m128i * aa = (__m128i*)(c+i);
                __m128i d = _mm_load_si128(bb++);
                __m128i d0 = _mm_shuffle_epi32(d, 0x00);
                __m128i d1 = _mm_shuffle_epi32(d, 0x55);
                __m128i d2 = _mm_shuffle_epi32(d, 0xAA);
                __m128i d3 = _mm_shuffle_epi32(d, 0xFF);
                for(uint ii=0; ii<B/8; ii++){
                    __m128i t0, t1, t2, t3;
                    __m128i c0 = _mm_load_si128(aa++);
                    __m128i c1 = _mm_load_si128(aa++);
                    __m128i c2 = _mm_load_si128(aa++);
                    __m128i c3 = _mm_load_si128(aa++);
                    t0 = _mm_add_epi32(c0, d0);
                    t1 = _mm_add_epi32(c1, d0);
                    t2 = _mm_add_epi32(c2, d0);
                    t3 = _mm_add_epi32(c3, d0);
                    s0 = _mm_xor_si128(s0, t0);
                    s1 = _mm_xor_si128(s1, t1);
                    s2 = _mm_xor_si128(s2, t2);
                    s3 = _mm_xor_si128(s3, t3);
                    t0 = _mm_add_epi32(c0, d1);
                    t1 = _mm_add_epi32(c1, d1);
                    t2 = _mm_add_epi32(c2, d1);
                    t3 = _mm_add_epi32(c3, d1);
                    s0 = _mm_xor_si128(s0, t0);
                    s1 = _mm_xor_si128(s1, t1);
                    s2 = _mm_xor_si128(s2, t2);
                    s3 = _mm_xor_si128(s3, t3);
                    t0 = _mm_add_epi32(c0, d2);
                    t1 = _mm_add_epi32(c1, d2);
                    t2 = _mm_add_epi32(c2, d2);
                    t3 = _mm_add_epi32(c3, d2);
                    s0 = _mm_xor_si128(s0, t0);
                    s1 = _mm_xor_si128(s1, t1);
                    s2 = _mm_xor_si128(s2, t2);
                    s3 = _mm_xor_si128(s3, t3);
                    t0 = _mm_add_epi32(c0, d3);
                    t1 = _mm_add_epi32(c1, d3);
                    t2 = _mm_add_epi32(c2, d3);
                    t3 = _mm_add_epi32(c3, d3);
                    s0 = _mm_xor_si128(s0, t0);
                    s1 = _mm_xor_si128(s1, t1);
                    s2 = _mm_xor_si128(s2, t2);
                    s3 = _mm_xor_si128(s3, t3);
                }
            }
        }
    }
    s0 = _mm_xor_si128(s0, s2);
    s1 = _mm_xor_si128(s1, s3);
    s0 = _mm_xor_si128(s0, s1);
    _mm_store_si128((__m128i*)ss, s0);
    ss[0] ^= ss[2];
    ss[1] ^= ss[3];
    ss[0] ^= ss[1];
    printf("%u\n", ss[0]^s);
    return 0;
}