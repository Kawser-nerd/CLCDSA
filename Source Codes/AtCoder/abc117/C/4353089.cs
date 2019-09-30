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
            var X = ReadLine().Split().Select(int.Parse).ToArray();

            X = X.OrderBy(x => x).ToArray();
            var len = new int[M - 1];
            for (int i = 0; i < len.Length; i++)
            {
                len[i] = X[i + 1] - X[i];
            }
            var ans = len.OrderBy(s => s).Take(M - N).Sum();
            WriteLine(ans);
        }
    }
}