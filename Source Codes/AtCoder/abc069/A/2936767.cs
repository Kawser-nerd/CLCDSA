using System;

class Program
{
  static void Main(string[] args)
  {
    string[] input = Console.ReadLine().Split(' ');
    int n = int.Parse(input[0]);
    int m = int.Parse(input[1]);
    
    Console.WriteLine("{0}", (n - 1) * (m - 1));
  }
}