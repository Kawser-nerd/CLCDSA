#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,sse4a,sse5,avx,avx2,avx512")

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <random>
#include <chrono>

typedef int ll;
typedef std::vector<ll> vl;
typedef std::vector<vl> vvl;

char getChar() {
    static char buffer[1 << 20];
    static int size = 0;
    static int pos = 0;
    if (pos == size) {
        size = (int)fread(buffer, 1, 1 << 20, stdin), pos = 0;
    }
    return pos == size ? -1 : buffer[pos++];
}

int read() {
    char c = '?';
    while (!(c == '-' || ('0' <= c && c <= '9'))) { c = getChar(); }
    bool neg = false;
    if (c == '-') { neg = true; c = getChar(); }
    int ret = 0;
    while ('0' <= c && c <= '9') { (ret *= 10) += (c - '0'); c = getChar(); }
    return neg ? -ret : ret;
}

const int mod = (int)1e9+7;

int add(int a, int b) {
    return (a += b) >= mod ? a - mod : a;
}

int mul(int a, int b) {
    return int(1LL * a * b % mod);
}

void rand_mat(vvl& m, int n) {
    uint64_t seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    seed ^= (uint64_t)(new uint64_t);
    std::mt19937 gen(seed);
    std::uniform_int_distribution<int> dist(0, mod-1);
    m.assign(n, vl(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            m[i][j] = dist(gen);
        }
    }
}

void input(int& n, vvl& A, vvl& B, vvl& C) {
    n = read();
    A.assign(n, vl(n, 0));
    C = B = A;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = read();
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            B[j][i] = read();
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = read();
        }
    }
}

int dot(int n, const vl& a, const vl& b) {
    int res = 0; const int gsize = 16;
    for (int g = 0; g + gsize <= n; g += gsize) {
        unsigned long long tmp = 0;
        int i = g;
        tmp = tmp + 1LL*a[i+0]*b[i+0] + 1LL*a[i+1]*b[i+1] + 1LL*a[i+2]*b[i+2] + 1LL*a[i+3]*b[i+3];
        tmp = tmp + 1LL*a[i+4]*b[i+4] + 1LL*a[i+5]*b[i+5] + 1LL*a[i+6]*b[i+6] + 1LL*a[i+7]*b[i+7];
        tmp = tmp + 1LL*a[i+8]*b[i+8] + 1LL*a[i+9]*b[i+9] + 1LL*a[i+10]*b[i+10] + 1LL*a[i+11]*b[i+11];
        tmp = tmp + 1LL*a[i+12]*b[i+12] + 1LL*a[i+13]*b[i+13] + 1LL*a[i+14]*b[i+14] + 1LL*a[i+15]*b[i+15];
        res = int((res + tmp) % mod);
    }
    for (int i = n / gsize * gsize; i < n; ++i) {
        res = add(res, mul(a[i], b[i]));
    }
    return res;
}

void mult(int n, const vvl& A, const vvl& B, vvl& R) {
    R.assign(n, vl(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            R[i][j] = dot(n, A[i], B[j]);
        }
    }
}

bool check(const int n, const vvl& A, const vvl& B) {
    for (int i = 0; i < n; ++i) {
        if (A[i] != B[i]) {
            return false;
        }
    }
    return true;
}

void gen(int n, vvl& A, vvl& B, vvl& C) {
    rand_mat(A, n), rand_mat(B, n), mult(n, A, B, C);
}

void test(int n) {
    vvl A, B, C;
    gen(n, A, B, C);
    //std::exit(0);
}

int main() {
    test(1000);
    int a, b; std::cin >> a >> b;
  	for (int c = 1; c <= 3; ++c) {
    	if (a * b * c % 2 == 1) {
        	std::cout << "Yes"; return 0;
        }
    }
  	std::cout << "No"; return 0;
    return 0;
}