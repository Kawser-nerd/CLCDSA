using System;
using System.Linq;

class Program {
  static void Main() {
    int a = Console.ReadLine().Split().Select(int.Parse).OrderBy(x => x).ToArray()[1];
    Console.WriteLine(a);
  }
}