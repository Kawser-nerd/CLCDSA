#include <cstdio>
#include <string>
#include <stack>

int main() {
  char buf[131072];
  scanf("%s", buf);
  std::string S = buf;

  int res = 0;
  std::stack<char> st;
  for (auto c: S) {
    if (st.empty() || st.top() == c) {
      st.push(c);
    } else {
      st.pop();
      res += 2;
    }
  }
  printf("%d\n", res);
}