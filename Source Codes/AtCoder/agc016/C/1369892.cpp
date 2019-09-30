#include <iostream>
using namespace std;
int H, W, h, w;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> H >> W >> h >> w;

  if ((H % h) == 0 && (W % w) == 0) {
    cout << "No" << endl;
    return 0;
  } 

  cout << "Yes" << endl;
  bool rev = false;
  if ((H % h) == 0) {
    swap(W, H);
    swap(w, h);
    rev = true;
  }
  // assert(H % h > 0);

  int c1 = 1 + 300000;
  int c2 = -h + (1 - h) * 300000;


  if (rev) {
    for(int j  = 0; j < W; ++j) {
      for(int i = 0; i < H; ++i) {
        if ((i % h) == h - 1) {
          cout << c2 << ' ';
        } else {
          cout << c1 << ' ';
        }
      }

      cout << '\n';
    }

    return 0;
  }

  // else
  for(int i = 0; i < H; ++i) {
    if ((i % h) == h - 1) {
      for(int j = 0; j < W; ++j) {
        cout << c2 << ' ';
      }
    } else {
      for(int j = 0; j < W; ++j) {
        cout << c1 << ' ';
      }
    }

    cout << '\n';
  }
}