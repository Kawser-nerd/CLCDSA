using System;

class Program
{
  static void Main()
  {
    var str = Console.ReadLine();
    var a = str.IndexOf('A');
    var z = str.LastIndexOf('Z');
    Console.WriteLine(z-a+1);
  }
}