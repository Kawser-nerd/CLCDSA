using System;

class Program
{
  static void Main(string[] args)
  {
    int a = int.Parse(Console.ReadLine());
    int b = int.Parse(Console.ReadLine());
    int n = int.Parse(Console.ReadLine());
    
    while(n % a != 0 || n % b != 0)
    {
      n++;
    }
    
    Console.WriteLine(n);
  }
}