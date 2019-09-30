using System;

class Program
{
  static void Main(string[] args)
  {
    int n = int.Parse(Console.ReadLine());
    
    if(n < 60) Console.WriteLine("Bad");
    else if(n < 90) Console.WriteLine("Good");
    else if(n < 100) Console.WriteLine("Great");
    else Console.WriteLine("Perfect");
  }
}