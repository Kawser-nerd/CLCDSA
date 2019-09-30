using System;
using System.Linq;

class Program {
  static void Main() {
    var arr = Console.ReadLine().Split().Select(decimal.Parse).ToArray();
    var a = arr[0];
    var b = arr[1];
    var c = arr[2];
    var d = arr[3];
    var T = b / a;
    var A = d / c;
    if (T > A) Console.WriteLine("TAKAHASHI");
    else if (T < A) Console.WriteLine("AOKI");
    else Console.WriteLine("DRAW");
  }
}