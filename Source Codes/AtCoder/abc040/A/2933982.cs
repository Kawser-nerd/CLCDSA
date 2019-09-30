using System;

class Program
{
  static void Main(string[] args)
  {
    string[] input = Console.ReadLine().Split(' ');
    int n = int.Parse(input[0]);
    int x = int.Parse(input[1]);
    
    if(2 * x <= n) Console.WriteLine(x - 1);
    else Console.WriteLine(n - x);
  }
}