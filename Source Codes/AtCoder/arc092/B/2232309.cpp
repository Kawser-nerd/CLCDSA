#include <stdio.h>
#include <algorithm>
#include <smmintrin.h>

using namespace std;

#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)

inline bool isd(char c){
  return '0'<=c && c<='9';
}

#define __my_getchar getchar
inline void read(int &x){
  x=0;char c;
  while(!isd(c=__my_getchar()));
  x=c-'0';
  while(isd(c=__my_getchar()))x=10*x+(c-'0');
}

#define AL16 __attribute__((aligned(16)))

// #define RANDOM_TEST
#define RANDOM_N 199999

#define N 200000

#define B 1600
#define BSZ (N / B)

int n;
#ifndef READ_A_LATER
int a[202521] AL16;
#endif
int b[202521] AL16;
int tmp[4] AL16;

int aa[B] AL16;

int main(){
  #ifndef RANDOM_TEST
  scanf("%d",&n);
  REP(i,n)read(b[i]);
  #else
  n = RANDOM_N;
  REP(i,n)b[i]=rand();
  #endif

  #ifndef RANDOM_TEST
  REP(i,n)read(a[i]);
  #else
  REP(i,n)a[i]=rand();
  #endif

  int ans = 0;
  REP(ii,BSZ){
    if(ii*B >= n)break;
    const int eee = n/B==ii ? (n - (n/B)*B) : B;
    __m128i xors = _mm_setzero_si128();
    REP(i,B/32){
      // 8 times loop unrolling
      _mm_store_si128((__m128i*)(aa+32*i+0x00), _mm_load_si128((__m128i*)(a+B*ii+32*i+0x00)));
      _mm_store_si128((__m128i*)(aa+32*i+0x04), _mm_load_si128((__m128i*)(a+B*ii+32*i+0x04)));
      _mm_store_si128((__m128i*)(aa+32*i+0x08), _mm_load_si128((__m128i*)(a+B*ii+32*i+0x08)));
      _mm_store_si128((__m128i*)(aa+32*i+0x0c), _mm_load_si128((__m128i*)(a+B*ii+32*i+0x0c)));
      _mm_store_si128((__m128i*)(aa+32*i+0x10), _mm_load_si128((__m128i*)(a+B*ii+32*i+0x10)));
      _mm_store_si128((__m128i*)(aa+32*i+0x14), _mm_load_si128((__m128i*)(a+B*ii+32*i+0x14)));
      _mm_store_si128((__m128i*)(aa+32*i+0x18), _mm_load_si128((__m128i*)(a+B*ii+32*i+0x18)));
      _mm_store_si128((__m128i*)(aa+32*i+0x1c), _mm_load_si128((__m128i*)(a+B*ii+32*i+0x1c)));
    }
    if(n%2==1){
      REP(i,B/32){
        // 8 times loop unrolling
        xors = _mm_xor_si128(xors, _mm_load_si128((__m128i*)(a+B*ii+32*i+0x00)));
        xors = _mm_xor_si128(xors, _mm_load_si128((__m128i*)(a+B*ii+32*i+0x04)));
        xors = _mm_xor_si128(xors, _mm_load_si128((__m128i*)(a+B*ii+32*i+0x08)));
        xors = _mm_xor_si128(xors, _mm_load_si128((__m128i*)(a+B*ii+32*i+0x0c)));
        xors = _mm_xor_si128(xors, _mm_load_si128((__m128i*)(a+B*ii+32*i+0x10)));
        xors = _mm_xor_si128(xors, _mm_load_si128((__m128i*)(a+B*ii+32*i+0x14)));
        xors = _mm_xor_si128(xors, _mm_load_si128((__m128i*)(a+B*ii+32*i+0x18)));
        xors = _mm_xor_si128(xors, _mm_load_si128((__m128i*)(a+B*ii+32*i+0x1c)));
      }
    }
    REP(jj,BSZ){
      REP(i,eee){
        __m128i aaaa = _mm_set1_epi32(aa[i]);
        __m128i *it = (__m128i*)(b + B*jj), *end = (__m128i*)(b + B*jj + B);
        while(it != end){
          xors = _mm_xor_si128(xors, _mm_add_epi32(aaaa, _mm_load_si128(it++)));
          xors = _mm_xor_si128(xors, _mm_add_epi32(aaaa, _mm_load_si128(it++)));
          xors = _mm_xor_si128(xors, _mm_add_epi32(aaaa, _mm_load_si128(it++)));
          xors = _mm_xor_si128(xors, _mm_add_epi32(aaaa, _mm_load_si128(it++)));
          xors = _mm_xor_si128(xors, _mm_add_epi32(aaaa, _mm_load_si128(it++)));
          xors = _mm_xor_si128(xors, _mm_add_epi32(aaaa, _mm_load_si128(it++)));
          xors = _mm_xor_si128(xors, _mm_add_epi32(aaaa, _mm_load_si128(it++)));
          xors = _mm_xor_si128(xors, _mm_add_epi32(aaaa, _mm_load_si128(it++)));
          xors = _mm_xor_si128(xors, _mm_add_epi32(aaaa, _mm_load_si128(it++)));
          xors = _mm_xor_si128(xors, _mm_add_epi32(aaaa, _mm_load_si128(it++)));
          xors = _mm_xor_si128(xors, _mm_add_epi32(aaaa, _mm_load_si128(it++)));
          xors = _mm_xor_si128(xors, _mm_add_epi32(aaaa, _mm_load_si128(it++)));
          xors = _mm_xor_si128(xors, _mm_add_epi32(aaaa, _mm_load_si128(it++)));
          xors = _mm_xor_si128(xors, _mm_add_epi32(aaaa, _mm_load_si128(it++)));
          xors = _mm_xor_si128(xors, _mm_add_epi32(aaaa, _mm_load_si128(it++)));
          xors = _mm_xor_si128(xors, _mm_add_epi32(aaaa, _mm_load_si128(it++)));
        }
      }
    }
    _mm_store_si128((__m128i*)tmp, xors);
    REP(i,4)ans ^= tmp[i];
  }
  printf("%d\n", ans);
  return 0;
}