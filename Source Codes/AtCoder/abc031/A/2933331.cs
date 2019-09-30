using System;

class Program
{
  static void Main(string[] args)
  {
    string[] input = Console.ReadLine().Split(' ');
    int a = int.Parse(input[0]);
    int d = int.Parse(input[1]);
    
    if((a + 1) * d >= a * (d + 1)) Console.WriteLine((a + 1) * d);
    else Console.WriteLine(a * (d + 1));
  }
}