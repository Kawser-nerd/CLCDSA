using System;
using System.Linq;

class Program {
  static void Main() {
    var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int L = arr[0] + arr[1];
    int r = arr[2] + arr[3];
    if (L > r) Console.WriteLine("Left");
    else if (L < r) Console.WriteLine("Right");
    else Console.WriteLine("Balanced");
  }
}