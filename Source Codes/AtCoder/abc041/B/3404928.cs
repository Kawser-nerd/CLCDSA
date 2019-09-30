using System;
using System.Linq;

class Program {
  static void Main() {
    var mod = 1000000007L;
    var arr = Console.ReadLine().Split().Select(long.Parse).ToArray();
    var a = arr[0];
    var b = arr[1];
    var c = arr[2];
    Console.WriteLine((a * b % mod) * c % mod);
  }
}