#include <iostream>

using namespace std;

int dir[300001];
int cnt[300001];

int main() {
  int n;
  cin >> n;

  char ch;
  for (int i = 1; i <= n; i++) {
    cin >> ch;
    dir[i] = ch == 'E' ? 1 : -1;
  }

  int c = 0;
  for (int i = 2; i <= n; i++) {
    if (dir[i] == -1) c++;
  }
  cnt[1] = c;
  for (int i = 2; i <= n; i++) {
    cnt[i] = cnt[i - 1];
    if (dir[i - 1] == 1) cnt[i]++;
    if (dir[i] == -1) cnt[i]--;
  }

  int max = 0;
  for (int i = 1; i <= n; i++) {
    if (max < cnt[i]) max = cnt[i];
  }

  cout << n - max - 1 << endl;
}