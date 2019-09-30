using System;
using System.Linq;

class Program {
  static void Main() {
    int n = int.Parse(Console.ReadLine());
    var arr = Console.ReadLine().Split().Select(int.Parse).OrderBy(x => x).ToArray();
    Console.WriteLine(arr[n - 1] - arr[0]);
  }
}