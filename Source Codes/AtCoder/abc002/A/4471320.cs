using System;

namespace ABC002 {
  class ProblemA {
    static void Main(string[] args) {
      string[] str = Console.ReadLine().Split(' ');

      int x = int.Parse(str[0]);
      int y = int.Parse(str[1]);

      System.Console.WriteLine(Math.Max(x, y));
    }
  }
}