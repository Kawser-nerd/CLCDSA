using System;

class Program
{
  static void Main(string[] args)
  {
    int n = int.Parse(Console.ReadLine());
    
    Console.WriteLine(800 * n - 200 * (n / 15));
  }
}