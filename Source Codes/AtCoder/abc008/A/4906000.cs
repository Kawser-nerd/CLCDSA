using System;

namespace ABC008 {
  class ProblemA {
    static void Main(string[] args) {
      string[] str = System.Console.ReadLine().Split(' ');
      int s = int.Parse(str[0]), t = int.Parse(str[1]);
      System.Console.WriteLine(t - s + 1);
    }
  }
}