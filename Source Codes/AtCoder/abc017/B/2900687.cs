using System;
using System.Linq;

class Program {
  static void Main() {
    var s = Console.ReadLine();
    var t = "choku";
    var choku = true;
    for (int i = 0; i < s.Length; i++) {
      if (!t.Contains(s[i])) {
        choku = false;
        break;
      } else if (s[i] == 'c') {
        if (i + 1 == s.Length || s[i + 1] != 'h') {
          choku = false;
          break;
        }
      } else if (s[i] == 'h') {
        if (i - 1 < 0 || s[i - 1] != 'c') {
          choku = false;
          break;
        }
      }
    }
    Console.WriteLine(choku ? "YES" : "NO");
  }
}