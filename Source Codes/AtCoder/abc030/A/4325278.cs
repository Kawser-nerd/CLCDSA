using System;
using System.Linq;
class Program {
  static void Main(string[] args) {
    int[] n = Console.ReadLine().Split(' ')
    .Select(i => int.Parse(i)).ToArray();
    int det = n[0]*n[3] - n[1]*n[2];
    if (det < 0) {
      Console.Write("TAKAHASHI\n");
    } else if (det > 0) {
      Console.Write("AOKI\n");
    } else {
      Console.Write("DRAW\n");
    }
  }
}