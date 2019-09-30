using System;
using System.Linq;

public class B{
  static void Main(string[] args)
  {            
    Console.ReadLine();
    var inputs = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
    Console.WriteLine(inputs.Max() - inputs.Min());
  }
}