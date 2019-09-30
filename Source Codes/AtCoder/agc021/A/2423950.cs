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
            long n = long.Parse(Console.ReadLine());
            long d = n.ToString().Length;
            long ans1 = n / (long)Math.Pow(10, d - 1) + 9 * (d - 1) - 1;
            long ans2 = Ans(n);
            Console.WriteLine(Math.Max(ans1, ans2));
        }
        static long Ans(long n)
        {
            int x = 0;
            for (int i = 0; i < n.ToString().Length; i++)
            {
                x += n.ToString()[i] - '0';
            }
            return x;
        }
    }
}