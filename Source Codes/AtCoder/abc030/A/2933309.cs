using System;

class Program
{
  static void Main(string[] args)
  {
    string[] input = Console.ReadLine().Split(' ');
    double a = double.Parse(input[0]);
    double b = double.Parse(input[1]);
    double c = double.Parse(input[2]);
    double d = double.Parse(input[3]);
    
    double x = b / a;
    double y = d / c;
    
    if(x > y) Console.WriteLine("TAKAHASHI");
    else if(x == y) Console.WriteLine("DRAW");
    else Console.WriteLine("AOKI");
  }
}