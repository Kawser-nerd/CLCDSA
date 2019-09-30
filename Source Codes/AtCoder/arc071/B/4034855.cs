using System;
using System.Linq;

namespace ARC071_D
{
    class Program
    {
        static void Main(string[] args)
        {
            var mod = 1000000007;
            var nm = Console.ReadLine().Split().Select(long.Parse).ToArray();
            var n = nm[0];
            var m = nm[1];
            var x = Console.ReadLine().Split().Select(long.Parse).ToArray();
            var y = Console.ReadLine().Split().Select(long.Parse).ToArray();

            long sumx = 0;
            for (long i = 1; i < n + 1; i++)
            {
                sumx += (i - 1) * x[i - 1] - (n - i) * x[i - 1];
                sumx %= mod;
            }

            long sumy = 0;
            for (long i = 1; i < m + 1; i++)
            {
                sumy += (i - 1) * y[i - 1] - (m - i) * y[i - 1];
                sumy %= mod;
            }

            Console.WriteLine(sumx * sumy % mod);

        }
    }
}