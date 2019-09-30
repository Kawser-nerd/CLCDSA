using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProblemA
{
    class Program
    {
        static long gcd(long a, long b)
        {
            if (b == 0) return a;
            else return gcd(b, a % b);
        }

        static bool Check(long n, long a, long b, long c, long d)
        {
            if (n / b < 1) return false;
            if ((a != 0) && (c == 0)) return false;
            if ((a != b) && (c == d)) return false;
            return true;
        }

        static void Main(string[] args)
        {
            long totalCase = Convert.ToInt64(Console.ReadLine());
            for (long curCase = 0; curCase < totalCase; ++curCase)
            {
                string[] str = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                long n = Convert.ToInt64(str[0]);
                long a = Convert.ToInt64(str[1]);
                long c = Convert.ToInt64(str[2]);
                long ta = gcd(a, 100);
                long tc = gcd(c, 100);
                a /= ta;
                c /= tc;
                long b = 100 / ta;
                long d = 100 / tc;
                if (Check(n, a, b, c, d)) Console.WriteLine("Case #{0}: Possible", curCase + 1);
                else Console.WriteLine("Case #{0}: Broken", curCase + 1);
            }
        }
    }
}
