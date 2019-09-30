using System;
using System.Linq;

class Program {
  static void Main() {
    var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int k = arr[1];
    var a = Console.ReadLine().Split().Select(int.Parse).OrderByDescending(x => x).Take(k).Sum();
    Console.WriteLine(a);
  }
}