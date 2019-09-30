using System;
public class A{
  static void Main(string[] args)
  {
    var input = int.Parse(Console.ReadLine());
    Console.WriteLine(Math.Floor(input/2.0)*Math.Ceiling(input/2.0));
  }
}