using System;
using System.Linq;
using System.Collections.Generic;
using static System.Math;
using static System.Console;

namespace AtCoder
{
    class AtCoderrrrrr
    {
        static void Main(string[] args)
        {
            int N = int.Parse(ReadLine());
            long power = 1;
            for (int i = 1; i <= N; i++)
            {
                power *= i;
                power %= 1000000007;
            }
            WriteLine(
                power
                );
        }
    }
}