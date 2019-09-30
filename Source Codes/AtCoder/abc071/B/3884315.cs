using System;
using System.Linq;
class B{
  static void Main(){
    var e = "abcdefghijklmnopqrstuvwxyz".Except(Console.ReadLine());
    Console.WriteLine(e.Any()?e.Min().ToString():"None");
  }
}