using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace R2P2
{
    class Program
    {
        static void Main(string[] args)
        {
            var testCount = int.Parse(Console.ReadLine());
            for (int testNumber = 1; testNumber <= testCount; testNumber++)
            {
                var parts = Console.ReadLine().Split().Select(long.Parse).ToArray();
                long N = parts[0];
                long P = parts[1];

                long n = 1;
                for (int i = 0; i < N; i++)
                    n *= 2;

                long c = P;
                long dCount = -1;
                while (c > 0)
                {
                    c >>= 1;
                    dCount++;
                }
                long neededBelow = 1;
                for (int i = 0; i < N - dCount; i++)
                {
                    neededBelow *= 2;
                }

                c = P - 1;
                long rP = 0;
                for (int i = 0; i < N; i++)
                {
                    long digit;
                    c = Math.DivRem(c, 2, out digit);
                    rP = rP * 2 + digit;
                }
                long lossCount = 0;
                while (rP % 2 == 1)
                {
                    lossCount++;
                    rP /= 2;
                }
                long allowedAbove = 1;
                for (int i = 0; i <= lossCount; i++)
                {
                    allowedAbove *= 2;
                }

                Console.WriteLine("Case #{0}: {1} {2}", testNumber, P < n ? allowedAbove - 2 : P - 1, n - neededBelow);
            }
        }
    }
}
