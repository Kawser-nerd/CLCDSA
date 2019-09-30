using System;
using System.Linq;

public class B{
  static void Main(string[] args)
  {
    var inputs = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse).OrderByDescending(x => x).ToArray();
    Console.WriteLine(inputs[0] * 10 + inputs[1] + inputs[2]);
  }
}