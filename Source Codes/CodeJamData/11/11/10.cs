using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProgrammingContest.GoogleCodeJam._2011.Round1.A
{
    class FreeCell_Statistics
    {
        static long[] ReadLongs() { return Array.ConvertAll(Console.ReadLine().Split(' '), sss => long.Parse(sss)); }
        static long gcd(long n, long r) { return r == 0 ? n : gcd(r, n % r); }

        static void Main()
        {
            int T = int.Parse(Console.ReadLine());
            for (int t = 0; t < T; t++)
            {
                var xs = ReadLongs();
                long N = xs[0],
                    pd = xs[1],
                    pg = xs[2];
                if (0 < pd && pg == 0 ||
                    pd < 100 && pg == 100)
                {
                    Console.WriteLine("Case #{0}: Broken", t+1);
                    continue;
                }
                long g = gcd(pd, 100 - pd);
                if (pd / g + (100 - pd) / g <= N)
                    Console.WriteLine("Case #{0}: Possible", t+1);
                else
                    Console.WriteLine("Case #{0}: Broken", t+1);
                // a/(a+b)*100 = a/D*100 = pd
                // (100-pd)*a = pd*b
                // 20*a = 80*b => a = 4*b
            }
        }
    }
}
