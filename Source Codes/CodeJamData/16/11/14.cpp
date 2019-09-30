#include <bits/stdc++.h>
using namespace std;

int n;
char c[100005];
int t;
int main() {
  scanf("%d", &t);
  for (int cs = 0; cs < t; cs++) {
    scanf("%s", c);
    string front;
    string back;
    n = strlen(c);
    for (int i = n - 1; i >= 0; i--) {
      bool can = true;
      for (int j = i; j >= 0; j--) {
        if (c[i] < c[j]) {
          can = false;
        }
      }
      if (can) {
        front.append(1, c[i]);
      } else {
        back.append(1, c[i]);
      }
    }
    reverse(back.begin(), back.end());
    printf("Case #%d: %s%s\n", cs + 1, front.c_str(), back.c_str());
  }

}

