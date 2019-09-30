using System;
using System.Linq;

class Program {
  static void Main() {
    var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int a = arr[0];
    int b = arr[1];
    int c = arr[2];
    int n = 1;
    while (true) {
      if ((n * a + c) % b == 0) {
        Console.WriteLine("YES");
        break;
      }
      n++;
      if (n * a % b == a % b) {
        Console.WriteLine("NO");
        break;
      }
    }
  }
}