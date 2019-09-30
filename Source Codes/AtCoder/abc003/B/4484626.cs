using System;

namespace ABC003 {
  class ProblemB {
    static void Main(string[] args) {
      string s = Console.ReadLine(), t = Console.ReadLine();
      bool[] flag = new bool[s.Length];
      bool ret = true;
      for (int i = 0; i < flag.Length; i++) {
        flag[i] = true;
      }
      
      for (int i = 0; i < s.Length; i++) {
        if (s[i] == '@') {
          if (!isAtcoder(t, i)) {
            flag[i] = false;
          }
        } else if (t[i] == '@') {
          if (!isAtcoder(s, i)) {
            flag[i] = false;
          }
        } else if (s[i] != t[i]) {
          flag[i] = false;
        }
        ret = ret && flag[i];
      }

      System.Console.WriteLine(ret ? "You can win" : "You will lose");
    }
    static bool isAtcoder(string str, int index) {
      if (
        str[index] == 'a' || str[index] == 't' || str[index] == 'c' || str[index] == 'o' ||
        str[index] == 'd' || str[index] == 'e' || str[index] == 'r' || str[index] == '@'
        ) {
          return true;
        } else {
          return false;
        }
    }
  }
}