using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class Program {
  static void Main(string[] args) {
    var n = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int x = n[0];
    int a = n[1];
    int b = n[2];
    if (Math.Abs(x - a) < Math.Abs(x - b)) {
      Console.WriteLine("A");
    } else {
      Console.WriteLine("B");
    }
  }
}