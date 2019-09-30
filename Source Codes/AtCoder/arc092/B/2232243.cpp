#include <stdio.h>
#include <algorithm>
#include <ctype.h>
#include <assert.h>
#include <smmintrin.h>

using namespace std;

#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)

// #define __my_getchar getchar_unlocked
// inline void read(int &x){
//   x=0;char c;
//   while(!isdigit(c=__my_getchar()));
//   x=c-'0';
//   while(isdigit(c=__my_getchar()))x=10*x+(c-'0');
// }

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

char buf[2000000];

inline bool isd(char c){
  return '0'<=c && c<='9';
}

int main(){
  #ifndef RANDOM_TEST
  scanf("%d",&n);
  fgets(buf, 10, stdin);
  // REP(i,n)scanf("%d",b+i);
  // REP(i,n)read(b[i]);
  {
    fgets(buf, 2000000, stdin);
    int i = 0;
    int x = 0;
    char *it = buf;
    while(i<n){
      if(isd(*it)){
        x = x*10 + (*it-'0');
      }else{
        b[i++] = x;
        x = 0;
      }
      it++;
    }
  }
  #else
  n = RANDOM_N;
  REP(i,n)b[i]=rand();
  #endif

  // if(n==2)return 0;

  #ifndef RANDOM_TEST
  // REP(i,n)scanf("%d",a+i);
  // REP(i,n)read(a[i]);
  {
    fgets(buf, 2000000, stdin);
    int i = 0;
    int x = 0;
    char *it = buf;
    while(i<n){
      if(isd(*it)){
        x = x*10 + (*it-'0');
      }else{
        a[i++] = x;
        x = 0;
      }
      it++;
    }
  }
  #else
  REP(i,n)a[i]=rand();
  #endif

  int ans = 0;
  REP(ii,BSZ){
    if(ii*B >= n)break;
    const int eee = n/B==ii ? (n - (n/B)*B) : B;
    __m128i xors = _mm_setzero_si128();
    // REP(i,B/32){
    //   _mm_store_si128((__m128i*)(aa+32*i+0x00), _mm_load_si128((__m128i*)(a+B*ii+32*i+0x00)));
    //   _mm_store_si128((__m128i*)(aa+32*i+0x04), _mm_load_si128((__m128i*)(a+B*ii+32*i+0x04)));
    //   _mm_store_si128((__m128i*)(aa+32*i+0x08), _mm_load_si128((__m128i*)(a+B*ii+32*i+0x08)));
    //   _mm_store_si128((__m128i*)(aa+32*i+0x0c), _mm_load_si128((__m128i*)(a+B*ii+32*i+0x0c)));
    //   _mm_store_si128((__m128i*)(aa+32*i+0x10), _mm_load_si128((__m128i*)(a+B*ii+32*i+0x10)));
    //   _mm_store_si128((__m128i*)(aa+32*i+0x14), _mm_load_si128((__m128i*)(a+B*ii+32*i+0x14)));
    //   _mm_store_si128((__m128i*)(aa+32*i+0x18), _mm_load_si128((__m128i*)(a+B*ii+32*i+0x18)));
    //   _mm_store_si128((__m128i*)(aa+32*i+0x1c), _mm_load_si128((__m128i*)(a+B*ii+32*i+0x1c)));
    // }
    if(n%2==1){
      REP(i,B/32){
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
        __m128i aaaa = _mm_set1_epi32(a[B*ii + i]);
        __m128i *it = (__m128i*)(b + B*jj), *end = (__m128i*)(b + B*jj + B);
        while(it != end){
          __m128i bbbb;
          
          bbbb = _mm_load_si128(it++); bbbb = _mm_add_epi32(bbbb, aaaa); xors = _mm_xor_si128(xors, bbbb);
          bbbb = _mm_load_si128(it++); bbbb = _mm_add_epi32(bbbb, aaaa); xors = _mm_xor_si128(xors, bbbb);
          bbbb = _mm_load_si128(it++); bbbb = _mm_add_epi32(bbbb, aaaa); xors = _mm_xor_si128(xors, bbbb);
          bbbb = _mm_load_si128(it++); bbbb = _mm_add_epi32(bbbb, aaaa); xors = _mm_xor_si128(xors, bbbb);
          bbbb = _mm_load_si128(it++); bbbb = _mm_add_epi32(bbbb, aaaa); xors = _mm_xor_si128(xors, bbbb);
          bbbb = _mm_load_si128(it++); bbbb = _mm_add_epi32(bbbb, aaaa); xors = _mm_xor_si128(xors, bbbb);
          bbbb = _mm_load_si128(it++); bbbb = _mm_add_epi32(bbbb, aaaa); xors = _mm_xor_si128(xors, bbbb);
          bbbb = _mm_load_si128(it++); bbbb = _mm_add_epi32(bbbb, aaaa); xors = _mm_xor_si128(xors, bbbb);
          bbbb = _mm_load_si128(it++); bbbb = _mm_add_epi32(bbbb, aaaa); xors = _mm_xor_si128(xors, bbbb);
          bbbb = _mm_load_si128(it++); bbbb = _mm_add_epi32(bbbb, aaaa); xors = _mm_xor_si128(xors, bbbb);
          
          bbbb = _mm_load_si128(it++); bbbb = _mm_add_epi32(bbbb, aaaa); xors = _mm_xor_si128(xors, bbbb);
          bbbb = _mm_load_si128(it++); bbbb = _mm_add_epi32(bbbb, aaaa); xors = _mm_xor_si128(xors, bbbb);
          bbbb = _mm_load_si128(it++); bbbb = _mm_add_epi32(bbbb, aaaa); xors = _mm_xor_si128(xors, bbbb);
          bbbb = _mm_load_si128(it++); bbbb = _mm_add_epi32(bbbb, aaaa); xors = _mm_xor_si128(xors, bbbb);
          bbbb = _mm_load_si128(it++); bbbb = _mm_add_epi32(bbbb, aaaa); xors = _mm_xor_si128(xors, bbbb);
          bbbb = _mm_load_si128(it++); bbbb = _mm_add_epi32(bbbb, aaaa); xors = _mm_xor_si128(xors, bbbb);
        }
      }
    }
    _mm_store_si128((__m128i*)tmp, xors);
    REP(i,4)ans ^= tmp[i];
  }
  printf("%d\n", ans);
  return 0;
}