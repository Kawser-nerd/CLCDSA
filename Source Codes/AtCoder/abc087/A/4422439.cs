using System;

class Program
{
  public static void Main(string[] args)
  {
    int x = int.Parse(Console.ReadLine());
    int a = int.Parse(Console.ReadLine());
    int b = int.Parse(Console.ReadLine());
    x -= a;
    x %= b;
    Console.WriteLine(x);
  }
}