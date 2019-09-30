using System;
using System.Linq;

class Program {
  static void Main() {
    int n = int.Parse(Console.ReadLine());
    string s = Console.ReadLine();
    string t = "b";
    string u = "abc";
    foreach (var c in s) {
      if (!u.Contains(c)) {
        Console.WriteLine(-1);
        return;
      }
    }
    if ((n & 1) == 0) {
      Console.WriteLine(-1);
      return;
    }
    int k = n / 2;
    for (int i = 1; i <= k; i++) {
      if (i % 3 == 1)  t = "a" + t + "c";
      else if (i % 3 == 2) t = "c" + t + "a";
      else t = "b" + t + "b";
    }
    if (s == t) {
      Console.WriteLine(k);
    } else {
      Console.WriteLine(-1);
    }
  }
}