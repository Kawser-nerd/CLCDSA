using System;

class Program
{
  static void Main(string[] args)
  {
    string[] input = Console.ReadLine().Split(' ');
    int a = int.Parse(input[0]);
    int b = int.Parse(input[1]);
    
    if(a + b < 10) Console.WriteLine("{0}", a + b);
    else Console.WriteLine("error");
  }
}