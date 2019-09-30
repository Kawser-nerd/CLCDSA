using System;
using System.Linq;

public class A{
  static void Main(string[] args)
  {
    var input = Int32.Parse(Console.ReadLine());
    Console.WriteLine(input < 1200 ? "ABC" : input < 2800 ? "ARC" : "AGC");
  }
}