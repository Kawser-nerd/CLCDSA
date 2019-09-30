using System;
using System.Linq;
class A{
  static void Main(){
    var s = Console.ReadLine().Split().Select(int.Parse);
    var p = int.Parse(Console.ReadLine());
    var m = s.Max();
    Console.WriteLine(s.Sum()-m+m*Math.Pow(2,p));
  }
}