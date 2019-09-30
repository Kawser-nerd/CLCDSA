using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
           Console.WriteLine(ABC121_C());
        }

        static long ABC121_C()
        {
            var NM = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
            var N = NM[0];
            var M = NM[1];
            var AB = new List<List<long>>();

            for (var n = 0; n < N; n++)
            {
                var ab = Console.ReadLine().Split(' ').Select(long.Parse).ToList();
                AB.Add(ab);
            }

            var ans = 0L;
            var count = 0L;
            var ordered = AB.OrderBy(x => x[0]);
            foreach (var ab in ordered)
            {
                if (count == M) break;
                if (count + ab[1] > M)
                {
                    ans += ab[0] * (M - count);
                    count += (M - count);
                }
                else
                {
                    ans += ab[0] * ab[1];
                    count += ab[1];
                }
            }
            return ans;
        }
    }
}