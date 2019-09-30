using System;
using System.Linq;

class Program {
  static bool D(string s) {
    foreach (var c in s) {
      if (c == '-') return false;
    }
    return true;
  }

  static void Main() {
    var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int a = arr[0];
    int b = arr[1];
    var s = Console.ReadLine();
    if (D(s.Substring(0, a)) && s.Substring(a, 1) == "-" && D(s.Substring(a + 1))) {
      Console.WriteLine("Yes");
    } else {
      Console.WriteLine("No");
    }
  }
}