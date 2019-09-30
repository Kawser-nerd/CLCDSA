#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string code  = "................z........q";

void process(string b, string a) {
  for (int i = 0; i < a.size(); i++)
    if (isalpha(a[i])) {
      if (code[b[i]-'a'] != a[i] && code[b[i]-'a'] != '.')
        cout << "CONFLICT!" << endl;
      code[b[i]-'a'] = a[i];
    }
}

main() {
  process("ejp mysljylc kd kxveddknmc re jsicpdrysi",
          "our language is impossible to understand");
  process("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
          "there are twenty six factorial possibilities");
  process("de kr kd eoya kw aej tysr re ujdr lkgc jv",
          "so it is okay if you want to just give up");

  int T, prob=1;
  for (scanf("%d ", &T); T--;) {
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++)
      if (isalpha(s[i])) s[i] = code[s[i]-'a'];
    cout << "Case #" << prob++ << ": " << s << endl;
  }
}
