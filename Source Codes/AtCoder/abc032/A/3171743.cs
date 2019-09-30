using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main(string[] args)
    {

            // ??
            long iA = long.Parse(Console.ReadLine().Trim());
            long iB = long.Parse(Console.ReadLine().Trim());
            long iN = long.Parse(Console.ReadLine().Trim());

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            long iL = Lcm(iA, iB);
            long iR = iL;
            long i = 2;
            while (iR < iN)
            {
                iR = iL * i;
                i += 1;
            }

            // ??
            Console.WriteLine("{0}", iR.ToString());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif

    }

        // ???????
        private static long Lcm(long a, long b)
        {
            return a * b / Gcd(a, b);
        }

        // ???????
        private static long Gcd(long a, long b)
        {
            if (a < b) { return Gcd(b, a); }
            while (b != 0)
            {
                var remainder = a % b;
                a = b;
                b = remainder;
            }
            return a;
        }

}