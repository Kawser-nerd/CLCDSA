using System;

class Program
{
  static void Main(string[] args)
  {
    int r = int.Parse(Console.ReadLine());
    int g = int.Parse(Console.ReadLine());
    
    Console.WriteLine("{0}", 2 * g - r);
  }
}