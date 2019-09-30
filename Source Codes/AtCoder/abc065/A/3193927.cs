using System;
using System.Linq;

class Program {
  static void Main() {
    var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int x = arr[0];
    int a = arr[1];
    int b = arr[2];
    int t = b - a;
    if (t <= 0) Console.WriteLine("delicious");
    else if (t <= x) Console.WriteLine("safe");
    else Console.WriteLine("dangerous");
  }
}