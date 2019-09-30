using System;
using System.Linq;

class Program {
  static void Main() {
    var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int a = arr[0];
    int b = arr[1];
    arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int c = arr[0];
    int d = arr[1];
    if (a == c || a == d || b == c || b == d) {
      Console.WriteLine("YES");
    } else {
      Console.WriteLine("NO");
    }
  }
}