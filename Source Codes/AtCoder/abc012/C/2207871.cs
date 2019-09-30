using System;
class Program
{
  static void Main()
  {
    int N = int.Parse(Console.ReadLine());
    int M = 2025 - N;
    for(int i = 1; i < 10; i++)
    {
      if(M % i == 0 && M / i < 10)
      {
        Console.WriteLine(i+" "+"x"+" "+M / i);
      }
      else
      {
        i = i;
      }
    }
  }
}