using System;

class Program {
  static void Main() {
    var s = Console.ReadLine();
    var a = "";
    var cnt = 1;
    var t = s[0];
    for (int i = 1; i < s.Length; i++) {
      if (s[i] == t) {
        cnt++;
      } else {
        a = a + t + cnt;
        t = s[i];
        cnt = 1;
      }
    }
    a = a + t + cnt;
    Console.WriteLine(a);
  }
}