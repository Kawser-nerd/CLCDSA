#include <immintrin.h>
#include <cstdio>

int N;
int a[200000] __attribute__((aligned(64)));
int b[200000] __attribute__((aligned(64)));

int extract(__m128i ret) {
  __m128i t0 = _mm_shuffle_epi32(ret, 176); // [2,3,0,0]
  __m128i t1 = _mm_xor_si128(ret, t0); // [0^2,1^3,x,x]
  __m128i t2 = _mm_shuffle_epi32(t1, 64); // [1^3,x,x,x]
  __m128i t3 = _mm_xor_si128(t1, t2); // [0^2^1^3,x,x,x]
  int rl = _mm_extract_epi16(t3, 6);
  int rh = _mm_extract_epi16(t3, 7);
  return rl + (rh << 16);
}

#define process_xor(src) \
  c0 = _mm_add_epi32(a0, (src)); \
  c1 = _mm_add_epi32(a1, (src)); \
  c2 = _mm_add_epi32(a2, (src)); \
  c3 = _mm_add_epi32(a3, (src)); \
  c4 = _mm_add_epi32(a4, (src)); \
  c5 = _mm_add_epi32(a5, (src)); \
  c6 = _mm_add_epi32(a6, (src)); \
  c7 = _mm_add_epi32(a7, (src)); \
  c8 = _mm_add_epi32(a8, (src)); \
  c9 = _mm_add_epi32(a9, (src)); \
  r0 = _mm_xor_si128(r0, c0); \
  r0 = _mm_xor_si128(r0, c1); \
  r0 = _mm_xor_si128(r0, c2); \
  r0 = _mm_xor_si128(r0, c3); \
  r0 = _mm_xor_si128(r0, c4); \
  r0 = _mm_xor_si128(r0, c5); \
  r0 = _mm_xor_si128(r0, c6); \
  r0 = _mm_xor_si128(r0, c7); \
  r0 = _mm_xor_si128(r0, c8); \
  r0 = _mm_xor_si128(r0, c9); 


int solve() {
  // port0 vec alu, 
  // port1 vec alu, vec shuf
  // port5 vec alu, vec shuf
  // port2, port3 load
  __m128i r0 = _mm_setzero_si128(); // pxor 1l/3t
  int ri = 0;
  
  int DI = 10;
  int DJ = 24;
  int NI = N / DI * DI;
  int NJ = N / DJ * DJ;

  for(int i=0;i<NI;i+=DI) {
    int aa = a[i];
    int ab = a[i+1];
    int ac = a[i+2];
    int ad = a[i+3];
    int ae = a[i+4];
    int af = a[i+5];
    int ag = a[i+6];
    int ah = a[i+7];
    int ai = a[i+8];
    int aj = a[i+9];

    __m128i a0 = _mm_set_epi32(aa, aa, aa, aa); // movd, pshufd
    __m128i a1 = _mm_set_epi32(ab, ab, ab, ab);
    __m128i a2 = _mm_set_epi32(ac, ac, ac, ac);
    __m128i a3 = _mm_set_epi32(ad, ad, ad, ad);
    __m128i a4 = _mm_set_epi32(ae, ae, ae, ae);
    __m128i a5 = _mm_set_epi32(af, af, af, af);
    __m128i a6 = _mm_set_epi32(ag, ag, ag, ag);
    __m128i a7 = _mm_set_epi32(ah, ah, ah, ah);
    __m128i a8 = _mm_set_epi32(ai, ai, ai, ai);
    __m128i a9 = _mm_set_epi32(aj, aj, aj, aj);
    
    for(int j=0;j<NJ;j+=DJ) {
      __m128i b0, b1, b2, b3, b4, b5;
      __m128i c0, c1, c2, c3, c4, c5, c6, c7, c8, c9;
      b0 = _mm_load_si128((__m128i *const)&b[j]); // movdqa 1l/2t
      b1 = _mm_load_si128((__m128i *const)&b[j+4]); // movdqa 1l/2t
      b2 = _mm_load_si128((__m128i *const)&b[j+8]); // movdqa 1l/2t
      b3 = _mm_load_si128((__m128i *const)&b[j+12]); // movdqa 1l/2t
      b4 = _mm_load_si128((__m128i *const)&b[j+16]); // movdqa 1l/2t
      b5 = _mm_load_si128((__m128i *const)&b[j+20]); // movdqa 1l/2t
      process_xor(b0);
      process_xor(b1);
      process_xor(b2);
      process_xor(b3);
      process_xor(b4);
      process_xor(b5);
    }

    for(int j=NJ;j<N;j++) {
      ri ^= aa + b[j];
      ri ^= ab + b[j];
      ri ^= ac + b[j];
      ri ^= ad + b[j];
      ri ^= ae + b[j];
      ri ^= af + b[j];
      ri ^= ag + b[j];
      ri ^= ah + b[j];
      ri ^= ai + b[j];
      ri ^= aj + b[j];
    }

  }

  for(int i=NI;i<N;i++)
    for(int j=0;j<N;j++) 
      ri ^= a[i] + b[j];

  return ri ^ extract(r0);
}

int main() {
  scanf("%d", &N);
  for(int i=0;i<N;i++) {
    scanf("%d", a+i);
  }
  for(int i=0;i<N;i++) {
    scanf("%d", b+i);
  }
  int ans = solve();
  printf("%d\n", ans);
  return 0;
}