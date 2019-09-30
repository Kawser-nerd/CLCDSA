using System;
using System.IO;

namespace CodeJam2017
{
    public class QR_B
    {
        public static void Solve(TextReader input, TextWriter output)
        {
            int t = Convert.ToInt32(input.ReadLine());

            for (int z = 1; z <= t; z++)
            {
                long n = Int64.Parse(input.ReadLine());
                long b = 1000000000000000000;
                long r = b;

                while (b > 0)
                {
                    long x = n / r % 10;
                    long y = n / b % 10;

                    if (x > y) break;
                    if (x < y) r = b;

                    b /= 10;
                }

                r = (b > 0) ? n / r * r - 1 : n;

                output.WriteLine("Case #{0}: {1}", z, r);
            }
        }
    }
}
