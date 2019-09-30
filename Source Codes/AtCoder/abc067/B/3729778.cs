using System;
using System.Linq;
class P{
  static void Main(){
    var s=Console.ReadLine().Split();
    Console.WriteLine(Console.ReadLine().Split().Select(int.Parse).OrderBy(x=>-x).Take(int.Parse(s[1])).Sum());
  }
}