using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemA
{
    class Program
    {
        static long Calc(long p, long q)
        {
            if (p != 0 && q%p == 0)
            {
                var divRes = q/p;
                var val = (long)Math.Log(divRes, 2);
                var pow = Math.Pow(2, val);
                if (Math.Abs(pow - divRes) < 0.1)
                    return val;
                else
                    return long.MaxValue;
            }
            else
                return long.MaxValue;
        }

        public static long Gcd(long x1, long x2)
        {
            if (x1 < 0 || x2 < 0)
            {
                throw new ArgumentException("Cannot compute the GCD if one integer is negative.");
            }
            long a, b, g, z;

            if (x1 > x2)
            {
                a = x1;
                b = x2;
            }
            else
            {
                a = x2;
                b = x1;
            }

            if (b == 0) return 0;

            g = b;
            while (g != 0)
            {
                z = a % g;
                a = g;
                g = z;
            }
            return a;
        }

        static void Main(string[] args)
        {
            long maxPow = 1;
            for (int i = 0; i < 41; i++)
                maxPow *= 2;

            using (var sr = new StreamReader("input.txt"))
            using (var sw = new StreamWriter("output.txt") { AutoFlush = true })
            {
                Func<long[]> readIntArrLine = () => sr.ReadLine().Split(' ').Select(long.Parse).ToArray();

                var testCaseCount = readIntArrLine()[0];
                for (int iCase = 1; iCase <= testCaseCount; iCase++)
                {
                    var dataArgs = sr.ReadLine().Split('/').Select(long.Parse).ToArray();

                    var p = dataArgs[0];
                    var q = dataArgs[1];

                    var gcd = Gcd(p, q);
                    
                    p /= gcd;
                    q /= gcd;

                    var maxVal = maxPow;
                    while (maxVal > p)
                        maxVal /= 2;

                    var gcd2 = Gcd(q, maxVal);
                    q /= gcd2;

                    var result = (long) Math.Log(q, 2);
                    if (Math.Abs(Math.Pow(2, result) - q) > 0.1)
                        result = long.MaxValue;

                    //var v1 = Calc(p, q);
                    //var v2 = Calc(p - 1, q);

                    sw.WriteLine(String.Format(CultureInfo.InvariantCulture, "Case #{0}: {1}", iCase, result == long.MaxValue ? "impossible" : result.ToString()));
                }
            }
        }
    }
}
