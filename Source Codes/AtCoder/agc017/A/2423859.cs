using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            var np = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            var a = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            long c0 = a.Count(i => i % 2 == 0);
            long c1 = a.Count() - c0;
            long c0Pow = (long)Math.Pow(2, c0);
            long c1Odd = 0;
            long c1Even = 0;
            for (int i = 0; i <= c1; i++)
            {
                if (i % 2 == 0) c1Even += nCr(c1, i);
                else c1Odd += nCr(c1, i);
            }
            Console.WriteLine(np[1] == 0 ? c0Pow * c1Even : c0Pow * c1Odd);

        }
        static long nCr(long n, long r)
        {
            double x = 1;
            for (int i = 0; i < r; i++)
            {
                x *= n - i;
                x /= i + 1;
            }
            return (long)x;
        }
    }
}