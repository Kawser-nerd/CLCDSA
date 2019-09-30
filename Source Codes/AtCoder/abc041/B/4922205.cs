using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Math;


namespace Piza
{
    class Paiza
    {
        static void Main(string[] args)
        {
            long[] s = ReadLine().Split(' ').Select(long.Parse).ToArray();
            long a = s[0];
            long b = s[1];
            long c = s[2];
            long tmp = a*b % 1000000007;
            WriteLine(
                (tmp*c) % 1000000007
                );
        }
    }
}