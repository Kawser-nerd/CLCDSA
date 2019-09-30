#include <x86intrin.h>
//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

 
using tpl = tuple<char, int>;
typedef pair<int,int> pii;
typedef long long ll;

void fastStream(){cin.tie(0);std::ios_base::sync_with_stdio(0);}

#define ALIGNED(n) __attribute((aligned(n)))


struct TimeWatch{
  clock_t start_,end_;
  void start(){start_=clock();}
  double stop(){return (double)(clock()-start_)/CLOCKS_PER_SEC;}
};


int N;
ALIGNED(16) int A[200000];
ALIGNED(16) int B[200000];

void print(__m128i a){
    ALIGNED(16) int C[4];
    _mm_store_si128(reinterpret_cast<__m128i*>(C), a);
    for(int i = 0; i < 4; i++){
        cout << C[i] << " ";
    }
    cout << endl;
}


#define ONE_SEQUENCE(b)        \
    c = _mm_add_epi32(a1, b);  \
    d = _mm_xor_si128(c, d);   \
    c = _mm_add_epi32(a2, b);  \
    d = _mm_xor_si128(c, d);   \
    c = _mm_add_epi32(a3, b);  \
    d = _mm_xor_si128(c, d);   \
    c = _mm_add_epi32(a4, b);  \
    d = _mm_xor_si128(c, d);   \
    c = _mm_add_epi32(a5, b); \
    d = _mm_xor_si128(c, d);   \
    c = _mm_add_epi32(a6, b); \
    d = _mm_xor_si128(c, d);   \
    c = _mm_add_epi32(a7, b); \
    d = _mm_xor_si128(c, d);   \
    c = _mm_add_epi32(a8, b); \
    d = _mm_xor_si128(c, d);   \
    

int calc(int *A, int *B, int N){
    int i, j;

    __m128i d = {0};

    const int shift1 = (2 << 6) | (1 << 4) | (0 << 2) | (3 << 0);
    const int shift2 = (1 << 6) | (0 << 4) | (3 << 2) | (2 << 0);
    const int shift3 = (0 << 6) | (3 << 4) | (2 << 2) | (1 << 0);
    
    for(int i = 0; i < N / 8; i++){
        __m128i a1 = _mm_load_si128(reinterpret_cast<__m128i*>(&A[i*8 + 0]));
        __m128i a2 = _mm_shuffle_epi32(a1, shift1);
        __m128i a3 = _mm_shuffle_epi32(a1, shift2);
        __m128i a4 = _mm_shuffle_epi32(a1, shift3);

        __m128i a5 = _mm_load_si128(reinterpret_cast<__m128i*>(&A[i*8 + 4]));
        __m128i a6 = _mm_shuffle_epi32(a5, shift1);
        __m128i a7 = _mm_shuffle_epi32(a5, shift2);
        __m128i a8 = _mm_shuffle_epi32(a5, shift3);


        __m128i *p = reinterpret_cast<__m128i*>(B);
        for(int j = 0; j < N / 40; j++){
            __m128i b1 = _mm_load_si128(p + j * 10);
            __m128i b2 = _mm_load_si128(p + j * 10 + 1);
            __m128i b3 = _mm_load_si128(p + j * 10 + 2);
            __m128i b4 = _mm_load_si128(p + j * 10 + 3);
            __m128i b5 = _mm_load_si128(p + j * 10 + 4);
            __m128i b6 = _mm_load_si128(p + j * 10 + 5);
            __m128i b7 = _mm_load_si128(p + j * 10 + 6);
            __m128i b8 = _mm_load_si128(p + j * 10 + 7);
            __m128i b9 = _mm_load_si128(p + j * 10 + 8);
            __m128i b10 = _mm_load_si128(p + j * 10 + 9);

            __m128i c;


            ONE_SEQUENCE(b1);
            ONE_SEQUENCE(b2);
            ONE_SEQUENCE(b3);
            ONE_SEQUENCE(b4);
            ONE_SEQUENCE(b5);
            ONE_SEQUENCE(b6);
            ONE_SEQUENCE(b7);
            ONE_SEQUENCE(b8);
            ONE_SEQUENCE(b9);
            ONE_SEQUENCE(b10);
        }
    }


    ALIGNED(16) int C[4];
    _mm_store_si128((__m128i*)(C), d);

    int res = 0;
    for(i = 0; i < 4; i++){
        res ^= C[i];
    }

    // ?????
    for(i = N / 40 * 40; i < N; i++){
        for(j = 0; j < N; j++){
            res ^= (A[j] + B[i]);
        }
    }

    for(int i = N / 8 * 8; i < N; i++){
        for(int j = 0; j < N / 40 * 40; j++){
            res ^= (B[j] + A[i]);
        }
    }
    return res;
 }


void simple(){
    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            ans ^= A[i] + B[j];
        }
    }
    cout << ans << endl;
}

void simd(){
    printf("%d\n", calc(A, B, N));
}

typedef long long ll;
// xor_shift
ll make_rand(){
  static ll x=123456789;
  static ll y=362436069;
  static ll z=521288629;
  static ll w=88675123;
  ll t;
  t=x^(x<<11);
  x=y;y=z;z=w;
  return w=(w^(w>>19))^(t^(t>>8));
}


int main(){

    int i;
    scanf("%d", &N);
    for(i = 0; i < N; i++) scanf("%d", A + i);
    for(i = 0; i < N; i++) scanf("%d", B + i);

    // N = 200000;
    // for(int i = 0; i < N; i++) A[i] = make_rand() % (1 << 28);
    // for(int i = 0; i < N; i++) B[i] = make_rand() % (1 << 28);

    //simple();
    simd();

    return 0;
}