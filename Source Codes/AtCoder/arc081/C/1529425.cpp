#include<cstdio>
#include<iostream>
using namespace std;

const int MAXN = 200010;
const int MAXM = 26;

int C[MAXN],F[MAXN][MAXM],A[MAXN];
string st;
int N;
char ch;

void output(int p, int c){
  if(c == 0) return;
  for(int i = 0; i < MAXM; i++) {
    if(F[p][i] == 0){
      printf("%c",'a'+i);
      return;
    }
    if(C[F[p][i]] < C[p]) {
      printf("%c",'a'+i);
      output(F[p][i],c-1);
      return;
    }
  }
}

int main(){
  cin >> st;
  N = st.length() + 1;
  for(int i = 1; i < N; i++) {
    A[i] = st[i-1] - 'a';
  }

  C[0] = 0;
  for(int i = N - 1; i >= 0; i--) {
    if(i < N - 1) {
      for(int j = 0; j < MAXM; j++){
        F[i][j] = F[i+1][j];
      }
      F[i][A[i + 1]] = i + 1;
    }
    C[i] = N;
    for(int j = 0; j < MAXM; j++) {
      int v = C[F[i][j]];
      if(F[i][j] == 0) {
        v = 0;
      }
      if (C[i] > v + 1) {
        C[i] = v + 1;
      }
    }
  }
  output(0,C[0]);
  return 0;
}