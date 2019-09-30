using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _1C
{
    class B
    {
        static void Main(string[] args)
        {
            int tests = int.Parse(Console.ReadLine());
            for (int te = 1; te <= tests; te++)
            {
                string[] s = Console.ReadLine().Split(' ');
                long l = long.Parse(s[0]), t = long.Parse(s[1]), n = long.Parse(s[2]), c = long.Parse(s[3]);

                long[] odl = new long[n];
                for (int i = 0; i < n; i++)
                {
                    odl[i] = long.Parse(s[4 + i % c]);
                }
                long j, time = 0, pom = 0;
                for (j = 0; j < n; j++)
                {
                    time += odl[j] * 2;
                    if (time > t)
                    {
                        pom = time;
                        time = t;
                        break;
                    }

                }
                if (j < n)
                {
                    List<long> max = new List<long>();
                    max.Add(pom - t);
                    j++;
                    for (; j < n; j++)
                        max.Add(odl[j] * 2);
                    max.Sort();
                    max.Reverse();
                    for (int k = 0; k < l && k < max.Count; k++)
                        max[k] /= 2;
                    time += max.Sum();
                }
                Console.WriteLine("Case #{0}: {1}", te, time);

            }
        }
    }
}
