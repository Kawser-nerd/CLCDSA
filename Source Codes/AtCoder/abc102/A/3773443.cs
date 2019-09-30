using System;
using System.Linq;

public class A{
  static void Main(string[] args)
  {
    var input = int.Parse(Console.ReadLine());
    Console.WriteLine(input % 2 == 0 ? input : input * 2);
  }
}