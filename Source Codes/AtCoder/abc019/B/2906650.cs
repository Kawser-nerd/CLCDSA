using System;
using System.Linq;

class Program {
  static void Main() {
    var s = Console.ReadLine();
    char t = s[0];
    int cnt = 1;
    for (int i = 1; i < s.Length; i++) {
      if (t == s[i]) {
        cnt++;
      } else {
        Console.Write("{0}{1}", t, cnt);
        t = s[i];
        cnt = 1;
      }
    }
    Console.WriteLine("{0}{1}", t, cnt);
  }
}