using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Round1CProblemA
{
    class Program
    {
        static void Main(string[] args)
        {
            var t = int.Parse(Console.ReadLine());
            for (var i = 1; i <= t; i++)
            {
                var parts = Console.ReadLine().Split(' ');
                var n = int.Parse(parts[0]);
                var k = int.Parse(parts[1]);
                var r = new long[n];
                var h = new long[n];
                for (var j = 0; j < n; j++)
                {
                    parts = Console.ReadLine().Split(' ');
                    r[j] = long.Parse(parts[0]);
                    h[j] = long.Parse(parts[1]);
                }

                Console.WriteLine($"Case #{i}: {Solve(n, k, r, h)}");
            }
        }

        private static double Solve(int n, int k, long[] r, long[] h)
        {
            var pancakes = Enumerable.Range(0, n).Select(i => new { r = r[i], h = h[i] }).OrderBy(tuple => tuple.r).ToArray();
            var cacheVertical = new Dictionary<Tuple<int, int>, long>(); // maximum possible vertical area for Tuple.Item2 pancakes. each having index no larger than Tuple.Item1
            for (var currentN = 0; currentN < n; currentN++)
            {
                for (var currentK = 0; currentK <= currentN + 1; currentK++)
                {
                    if (currentK == 0)
                    {
                        cacheVertical[Tuple.Create(currentN, currentK)] = 0;
                    }
                    else
                    {
                        //Console.WriteLine($"{currentN};{currentK}");
                        var tmp = 2 * pancakes[currentN].r * pancakes[currentN].h;
                        if (currentN > 0)
                        {
                            tmp += cacheVertical[Tuple.Create(currentN - 1, currentK - 1)];
                        }

                        if (currentK <= currentN)
                        {
                            var tmp2 = cacheVertical[Tuple.Create(currentN - 1, currentK)];
                            tmp = Math.Max(tmp, tmp2);
                        }

                        cacheVertical[Tuple.Create(currentN, currentK)] = tmp;
                    }
                }
            }

            var result = 0L;
            for (var currentN = k - 1; currentN < n; currentN++)
            {
                var tmp = pancakes[currentN].r * (pancakes[currentN].r + 2 * pancakes[currentN].h);
                if (currentN > 0)
                {
                    tmp += cacheVertical[Tuple.Create(currentN - 1, k - 1)];
                }
                result = Math.Max(result, tmp);
            }

            return Math.PI * (double)result;
        }
    }
}
