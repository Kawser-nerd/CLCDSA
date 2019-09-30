using System;
using System.Linq;

namespace AGC019A
{
    class Program
    {
        static void Main(string[] args)
        {
            long[] QHSD = Console.ReadLine().Split(' ').Select(a => long.Parse(a)).ToArray();
            long Q = QHSD[0];
            long H = QHSD[1];
            long S = QHSD[2];
            long D = QHSD[3];
            long N = long.Parse(Console.ReadLine());

            long ans = solve(Q, H, S, D, N);
            Console.WriteLine(ans);
        }

        static long solve(long Q, long H, long S, long D, long N)
        {
            long total = 0;

            long doubles = N / 2;
            long bestDoubleCost = Math.Min(Math.Min(Q * 8, H * 4), Math.Min(S * 2, D));

            total += bestDoubleCost * doubles;

            if (N % 2 == 1)
            {
                long bestSingleCost = Math.Min(Math.Min(Q * 4, H * 2), S);
                total += bestSingleCost;
            }

            return total;
        }
    }
}