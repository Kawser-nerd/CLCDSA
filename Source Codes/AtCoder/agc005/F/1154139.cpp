#include <cstdio>
#include <vector>

const int k = 19;
const int m = 1 << 19;

typedef int Zp;


const int mod = 924844033;
const int root = 5;

std::vector<int> G[200000];

int s[200000];

int fact[200001];
int ifact[200001];

Zp A[(1<<19)+1];
Zp B[(1<<19)+1];
Zp w[(1<<18)+1];
Zp y[(1<<18)+1];

const int mod10[200] = {
0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,
0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,
0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,
0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
};

const int div10[200] = {
0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,
5,5,5,5,5,5,5,5,5,5,6,6,6,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,9,9,9,9,9,9,9,9,9,9,
10,10,10,10,10,10,10,10,10,10,11,11,11,11,11,11,11,11,11,11,12,12,12,12,12,12,12,12,12,12,13,13,13,13,13,13,13,13,13,13,
14,14,14,14,14,14,14,14,14,14,15,15,15,15,15,15,15,15,15,15,16,16,16,16,16,16,16,16,16,16,17,17,17,17,17,17,17,17,17,17,
18,18,18,18,18,18,18,18,18,18,19,19,19,19,19,19,19,19,19,19
};


void read_uint(int *x){
  char c=0;
  while(c<'0') c = getchar_unlocked();

  *x = c-'0';
  c = getchar_unlocked();

  while(c>='0') {
    *x *= 10;
    *x += c-'0';
    c = getchar_unlocked();
  }
}

void write_uint(int x){
  int i;
  static char buf[13]="           \n";
  if(x==0){
    fputs_unlocked("0\n", stdout);
    return;
  }

  for(i=10; x; i--){
    if(x >= 200){
      buf[i] = '0' + x % 10;
      x /= 10;
    }
    else {
      buf[i] = '0' + mod10[x];
      x = div10[x];
    }
  }
  fputs_unlocked(buf+1+i, stdout);
}


Zp add(Zp lhs, Zp rhs){
  Zp r = lhs + rhs;
  if(r >= mod) return r - mod;
  else return r;
}

Zp sub(Zp lhs, Zp rhs){
  if(lhs >= rhs) return lhs - rhs;
  else return mod + lhs - rhs;
}

Zp mul(Zp lhs, Zp rhs){
  return ((long long) lhs * rhs) % mod;
}

Zp powr(Zp x, int n){
  Zp r = 1;
  for(; n; n>>=1){
    if(n&0x1) r = mul(r, x);
    x = mul(x, x);
  }
  return r;
}

Zp inv(Zp x){
  return powr(x, mod-2);
}


void fft(Zp *A){
  int u = 1;
  int v = m/2;
  for(int i=k;i>0;i--){
    for(int jh=0;jh<u;jh++){
      Zp wj = w[jh];
      for(int j = jh << i, je = j+v;j<je; j++){
        Zp Ajv = mul(wj, A[j+v]);
        A[j+v]  = sub(A[j], Ajv);
        A[j]   = add(A[j], Ajv);
      }
    }
    u <<= 1;
    v >>= 1;
  }
}

void ifft(Zp *A){
  int u = m/2;
  int v = 1;
  for(int i=1;i<=k;i++){
    for(int jh=0;jh<u;jh++){
      Zp wj = y[jh];
      for(int j = jh << i, je = j+v;j<je; j++){
        Zp Ajv = sub(A[j], A[j+v]);
        A[j] = add(A[j], A[j+v]);
        A[j+v] = mul(wj, Ajv);
      }
    }
    u >>= 1;
    v <<= 1;
  }
}


void genwy(int i, int b, Zp z, Zp x){
  if(b == 0) {
    w[i] = z;
    y[i] = x;
  }
  else {
    genwy(i, b>>1, z, x);
    genwy(i|b, b>>1, mul(z, w[b]), mul(x, y[b]));
  }
}

void init_fact(int n){
  fact[0] = 1;
  for(int i = 1; i <= n; i++){
    fact[i] = mul(fact[i-1], i);
  }
  ifact[n] = inv(fact[n]);
  for(int i = n-1; i >= 0; i--){
    ifact[i] = mul(ifact[i+1], i+1);
  }
}

int comb(int n, int k){
  return mul(mul(fact[n], ifact[n-k]), ifact[k]);
}

int makes(int i, int p){
  int sum = 0;
  for(unsigned int j = 0; j < G[i].size(); j++){
    int k = G[i][j];
    if(k == p) continue;
    sum += makes(k, i);
  }
  return s[i] = sum+1;
}

int main(){
  int n;
  read_uint(&n);
  for(int i=1;i<n;i++){
    int a, b;
    read_uint(&a);
    read_uint(&b);
    G[a-1].push_back(b-1);
    G[b-1].push_back(a-1);
  }

  init_fact(n);
  makes(0, -1);
  for(int i=1;i<n;i++){
      A[s[i]]++;
      A[n-s[i]]++;
  }
  B[0]=1;
  for(int i=1;i<=n;i++){
    A[i] = mul(A[i], fact[i]);
    B[m-i] = ifact[i];
  }
  Zp z=powr(root, mod>>k);
  Zp x=inv(z);
  for(int j=m/4; j; j>>=1){
    w[j] = z;
    z = mul(z, z);
    y[j] = x;
    x = mul(x, x);
  }
  genwy(0, m/4, 1, 1);
  fft(A);
  fft(B);
  for(int i=0;i<m;i++){
    A[i] = mul(A[i], B[i]);
  }
  ifft(A);
  Zp im = inv(m);
  for(int i=1;i<=n;i++){
    write_uint(sub(mul(n, comb(n, i)), mul(mul(A[i], im), ifact[i])));
  }
}