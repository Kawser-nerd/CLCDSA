using System;
using System.Linq;

class Program {
  static void Main() {
    var s = Console.ReadLine();
    var n = int.Parse(Console.ReadLine());
    while (n-- > 0) {
      var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
      int L = arr[0];
      int r = arr[1];
      var a = s.Substring(0, L - 1);
      var b = new string(s.Substring(L - 1, r - L + 1).Reverse().ToArray());
      var c = s.Substring(r);
      s = a + b + c;
    }
    Console.WriteLine(s);
  }
}