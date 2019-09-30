using System;

namespace ABC077B
{
  class Program
  {
    static void Main(string[] args)
    {
      int N = int.Parse(Console.ReadLine());
      int x = (int)Math.Sqrt(N);

      Console.WriteLine(x * x);
    }
  }
}