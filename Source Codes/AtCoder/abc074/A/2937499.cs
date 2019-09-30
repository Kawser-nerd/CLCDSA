using System;

class Program
{
  static void Main(string[] args)
  {
    int n = int.Parse(Console.ReadLine());
    int a = int.Parse(Console.ReadLine());
    
    Console.WriteLine("{0}", n * n - a);
  }
}