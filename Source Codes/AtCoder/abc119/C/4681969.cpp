#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int main(void) {
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  int l[n];
  for (int i = 0; i < n; i++) {
    cin >> l[i];
  }
  int min_mp = 1000000000;
  for (int i = 0; i < pow(2, n); i++) {
    int ii = pow(2, n) - 1 - i;
    vector<int> digit;
    for (int z = 0; z < n; z++) {
      if (((1 << z) & ii) > 0) {
        digit.push_back(z);
      }
    }
    for (int jj = 0; jj < pow(2, digit.size()); jj++) {
      int j = 0;
      for (vector<int>::iterator z = digit.begin(); z < digit.end(); z++) {
        if (((1 << (z-digit.begin())) & jj) > 0) {
          j += pow(2, *z);
        }
      }
      int kk = pow(2, n) - 1 - i - j;
      vector<int> dd;
      for (int z = 0; z < n; z++) {
        if (((1 << z) & kk) > 0) {
          dd.push_back(z);
        }
      }
      for (int kkk = 0; kkk < pow(2, dd.size()); kkk++) {
        int k = 0;
        for (vector<int>::iterator z = dd.begin(); z < dd.end(); z++) {
          if (((1 << (z-dd.begin())) & kkk) > 0) {
            k += pow(2, *z);
          }
        }
        //k = kk;
        /*
        if (j == 14 && kk == 16) {
          cout << i << endl;
          cout << j << endl;
          cout << k << endl;
          cout << kk << endl;
          cout << kkk << endl;
        }
        */

        int l_a = 0;
        int l_b = 0;
        int l_c = 0;
        int mp = 0;
        for (int q = 0; q < n; q++) {
          if (((1 << q) & i) > 0) {
            l_a += l[q];
            mp += 10;
          } else if (((1 << q) & j) > 0) {
            l_b += l[q];
            mp += 10;
          } else if (((1 << q) & k) > 0) {
            l_c += l[q];
            mp += 10;
          }
        }
        if (l_a == 0 || l_b == 0 || l_c == 0) {
          continue;
        }
        mp -= 30;
        mp += (abs(a - l_a) + abs(b - l_b) + abs(c - l_c));
        if (mp < min_mp)  min_mp = mp;
      }
    }
  }
  cout << min_mp << endl;
  return 0;
}