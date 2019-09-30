using System;
using System.Linq;

class Program {
  static void Main() {
    var s = Console.ReadLine();
    int n = int.Parse(Console.ReadLine());
    for (int i = 0; i < n; i++) {
      var t = Console.ReadLine().Split().Select(int.Parse).ToArray();
      int l = t[0];
      int r = t[1];
      var a = s.Substring(0, l - 1);
      var b = new string(s.Substring(l - 1, r - l + 1).Reverse().ToArray());
      var c = s.Substring(r);
      s = a + b + c;
    }
    Console.WriteLine(s);
  }
}