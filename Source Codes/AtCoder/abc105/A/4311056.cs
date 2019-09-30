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
            var K = raw[1];

            WriteLine(N % K == 0 ? 0 : 1);
        }
    }
}