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
            var N = int.Parse(ReadLine());
            var h = ReadLine().Split().Select(int.Parse).ToArray();

            var ans = h[0];
            for (int i = 1; i < N; i++)
            {
                if (h[i] > h[i - 1]) ans += h[i] - h[i - 1];
            }
            WriteLine(ans);
        }
    }
}