using System;

namespace A {
  class A {
    static int GetAnswer(string s, int k) {
      if (s.Length == k) {
        bool feasible = true;
        for (int i = 0; i < s.Length; i++) {
          if (s[i] != '+') {
            feasible = false;
            break;
          }
        }
        if (feasible) return 0;
        feasible = true;
        for (int i = 0; i < s.Length; i++) {
          if (s[i] != '-') {
            feasible = false;
            break;
          }
        }
        if (feasible) return 1;
        return -1;
      }
      if (s[0] == '+') return GetAnswer(s.Substring(1), k);
      String a = "";
      for (int i = 1; i < k; i++) {
        if (s[i] == '+') a += '-';
        else a += '+';
      }
      int ans = GetAnswer(a + s.Substring(k), k);
      if (ans == -1) return -1;
      return ans + 1;
    }

    static void Main() {
      string buf = Console.ReadLine();
      int t = int.Parse(buf);
      for (int ti = 1; ti <= t; ti++) {
        buf = Console.ReadLine();
        string[] ss = buf.Split();
        string s = ss[0];
        int k = int.Parse(ss[1]);
        int r = GetAnswer(s, k);
        if (r == -1)
          Console.WriteLine("Case #{0}: IMPOSSIBLE", ti);
        else
          Console.WriteLine("Case #{0}: {1}", ti, r);
      }
    }
  }
}
