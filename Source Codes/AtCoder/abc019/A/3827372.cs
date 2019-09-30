using System;
using System.Linq;
class A{
  static void Main(){
    var s = Console.ReadLine().Split().Select(int.Parse).OrderBy(x=>x).ToArray()[1];
    Console.WriteLine(s);
  }
}