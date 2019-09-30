using System;
using System.Collections.Generic;
using System.Linq;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = ReadArrayLong();
            var Q = input[0];
            var H = input[1];
            var S = input[2];
            var D = input[3];
            var N = ReadLong();
            var lit = Q * 4;
            if (lit > H * 2) lit = H * 2;
            if (lit > S) lit = S;
            var ans = 0L;
            if (lit * 2 > D && N >= 2)
            {
                if (N % 2 == 0)
                {
                    ans += (N / 2) * D;
                }
                else
                {
                    ans += (N / 2) * D + lit;
                }
            }
            else
            {
                ans += N * lit;
            }

            Console.WriteLine(ans);
            Console.ReadLine();
        }

        static string Read() { return Console.ReadLine(); }
        static int ReadInt() { return int.Parse(Read()); }
        static long ReadLong() { return long.Parse(Read()); }
        static int[] ReadArrayInt() { return Read().Split(' ').Select(s => int.Parse(s)).ToArray(); }
        static long[] ReadArrayLong() { return Read().Split(' ').Select(s => long.Parse(s)).ToArray(); }
    }
}