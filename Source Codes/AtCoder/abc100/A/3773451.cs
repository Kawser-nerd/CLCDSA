using System;
using System.Linq;

public class A{
  static void Main(string[] args)
  {
    var inputs = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
    Console.WriteLine(inputs[0] <= 8 && inputs[1] <= 8? "Yay!" : ":(");
  }
}