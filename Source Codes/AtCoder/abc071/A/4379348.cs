using System;
using System.Linq;
class Program {
  static void Main(string[] args) {
    int[] n = Console.ReadLine().Split(' ')
    .Select(i => int.Parse(i)).ToArray();
    if (Math.Abs(n[1]-n[0]) < Math.Abs(n[2]-n[0])) {
      Console.Write("A");
    } else {
      Console.Write("B");
    }
  }
}