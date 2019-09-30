using System;
using System.Linq;

public class A{
  static void Main(string[] args)
  {
    var input = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
    Console.WriteLine(input[0]-input[1]+1);
  }
}