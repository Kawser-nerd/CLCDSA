using System;

class Program
{
  static void Main(string[] args)
  {
    string[] input = Console.ReadLine().Split(' ');
    int x = int.Parse(input[0]);
    int y = int.Parse(input[1]);
    
    if(x < y) Console.WriteLine("Better");
    else Console.WriteLine("Worse");
  }
}