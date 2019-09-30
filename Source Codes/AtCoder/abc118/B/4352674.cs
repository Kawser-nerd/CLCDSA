using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;

namespace AtCoder
{
    class Program
    {
        static void Main()
        {
            var raw = ReadLine().Split().Select(int.Parse).ToArray();
            var N = raw[0];
            var M = raw[1];

            var favlist = new int[N][];
            for (int i = 0; i < N; i++)
            {
                raw = ReadLine().Split().Skip(1).Select(int.Parse).ToArray();
                favlist[i] = raw;
            }

            var ans = M;
            for (int i = 1; i <= M; i++)
            {
                foreach (var item in favlist)
                {
                    if (!item.Contains(i))
                    {
                        ans--;
                        break;
                    }
                }
            }

            WriteLine(ans);
        }
    }
}