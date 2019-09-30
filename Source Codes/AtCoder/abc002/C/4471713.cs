using System;

namespace ABC002 {
  class ProblemC {
    static void Main(string[] args) {
      string[] str = Console.ReadLine().Split(' ');

      int x1 = int.Parse(str[0]), y1 = int.Parse(str[1]);
      int x2 = int.Parse(str[2]), y2 = int.Parse(str[3]);
      int x3 = int.Parse(str[4]), y3 = int.Parse(str[5]);
    
      System.Console.WriteLine(AreaTriangle(x2 - x1, y2 - y1, x3 - x1, y3 - y1));
    }
    static double AreaTriangle(int x, int y, int z, int w) {
      return Math.Abs(x * w - y * z) / 2.0;
    }
  }
}