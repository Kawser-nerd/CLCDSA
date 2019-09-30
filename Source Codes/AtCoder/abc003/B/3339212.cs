using System;

class Program {
  static void Main() {
    var s = Console.ReadLine();
    var t = Console.ReadLine();
    var a = "@atcoder";
    for (int i = 0; i < s.Length; i++) {
      if (s[i] == t[i]) {
        continue;
      } else if((s[i] == '@' && a.Contains(t[i].ToString())) || (t[i] == '@' && a.Contains(s[i].ToString()))) {
        continue;
      } else {
        Console.WriteLine("You will lose");
        return;
      }
    }
    Console.WriteLine("You can win");
  }
}