using System.Linq;
using System;
class P{
  static void Main(){
    var s=Console.ReadLine();
    Console.WriteLine(string.Join(" ",Enumerable.Range('A',6).Select(x=>s.Count(y=>y==x))));
  }
}