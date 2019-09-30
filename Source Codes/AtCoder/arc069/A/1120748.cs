using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProgrammingContest_CSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            var e = Console.ReadLine().Split().Select(long.Parse).ToArray();
            long n = e[0], m = e[1];
            long ans = Solve(n, m);
            Console.WriteLine(ans);
        }

        private static long Solve(long n, long m)
        {
            long begin = 0, end = n + m;

            while (begin < end)
            {
                //Console.WriteLine($"{begin} {end}");
                long middle = (begin + end) / 2 + 1;

                if (CanCreate(middle, n, m))
                {
                    begin = middle;
                }
                else
                {
                    end = middle - 1;
                }
            }

            return begin;
        }

        private static bool CanCreate(long count, long n, long m)
        {
            long lack = Math.Max(count - n, 0);
            return m - lack * 2 >= count * 2;
        }
    }
}