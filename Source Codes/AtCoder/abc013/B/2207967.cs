using System;
class Program
{
  static void Main()
  {
    int a = int.Parse(Console.ReadLine());
    int b = int.Parse(Console.ReadLine());
    if(a > b)
    {
      Console.WriteLine(Math.Min(a - b, b - a + 10));
    }
    if(b > a)
    {
      Console.WriteLine(Math.Min(b - a, a - b + 10));
    }
  }
}