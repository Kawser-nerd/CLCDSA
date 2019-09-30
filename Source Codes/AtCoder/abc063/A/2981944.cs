using System;
using System.Linq;

class Program {
  static void Main() {
    var a = Console.ReadLine().Split().Select(int.Parse).ToArray();
    Console.WriteLine(a[0] + a[1] >= 10 ? "error" : "{0}", a[0] + a[1]);
  }
}