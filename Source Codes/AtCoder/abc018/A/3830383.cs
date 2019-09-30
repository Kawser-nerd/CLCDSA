using System;
using System.Linq;
class A{
  static void Main(){
    var s = (new string[] { Console.ReadLine(), Console.ReadLine(), Console.ReadLine() }).Select(int.Parse);
    foreach(var o in s.Select(x => s.OrderByDescending(y => y).ToList().IndexOf(x)))
      Console.WriteLine(o+1);
  }
}