using System;
using System.Linq;

class Program {
  static void Main() {
    var arr = Console.ReadLine().Split().Select(int.Parse).OrderByDescending(x => x).ToArray();
    int k = int.Parse(Console.ReadLine());
    arr[0] = arr[0] * (int)Math.Pow(2, k);
    Console.WriteLine(arr.Sum());
  }
}