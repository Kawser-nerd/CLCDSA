using System;

namespace AGC021A
{
  class Program
  {
    static void Main(string[] args)
    {
      long N = long.Parse(Console.ReadLine());
      int dig = (int)Math.Log10(N);
      long n = (long)Math.Pow(10, dig);
      long res = 0;


      if (N < (n - 1) * 2) {
        res = 9 * dig;
      } else {
        long k = N / n;
        if (n * (k + 1) - 1 > N) {
          res = 9 * dig + k - 1;
        }
        else {
          res = 9 * dig + k;
        }
      }

      Console.WriteLine(res);
    }
  }
}