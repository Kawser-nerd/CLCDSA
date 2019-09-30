#include<iostream>
#include<algorithm>

using namespace std;

using int64 = long long;

int main()
{
  int N, X[2000], Y[2000];
  int sqr[2000][2000];

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i];
  }
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      sqr[i][j] = (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]);
    }
  }

  int latte = 0, malta = 0;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < i; j++) {
      for(int k = 0; k < j; k++) {
        int a = sqr[i][j], b = sqr[j][k], c = sqr[k][i];
        if(a > b) swap(a, b);
        if(b > c) swap(b, c);

        if(c == a + b) ++latte;
        else if(c < a + b) ++malta;
      }
    }
  }

  int64 cur = 1LL * N * (N - 1) * (N - 2) / 6;

  cout << malta << " " << latte << " " << cur - latte - malta << endl;

}