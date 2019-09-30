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
            var N = input[0];
            var M = input[1];
            var S = Read();
            var T = Read();
            var G = Gcd(N, M);
            var L = Lcm(N, M);
            var n = N / G;
            var m = M / G;
            for (int i = 0; i < G; i++)
            {
                if (S[i * (int)n] != T[i * (int)m])
                {
                    Console.WriteLine(-1);
                    return;
                }
            }

            Console.WriteLine(L);
            Console.ReadLine();
        }

        static long Gcd(long a, long b) { if (b == 0) return a; return Gcd(b, a % b); }
        static long Lcm(long a, long b) { return a / Gcd(a, b) * b; }

        static string Read() { return Console.ReadLine(); }
        static int ReadInt() { return int.Parse(Read()); }
        static long ReadLong() { return long.Parse(Read()); }
        static int[] ReadArrayInt() { return Read().Split(' ').Select(s => int.Parse(s)).ToArray(); }
        static long[] ReadArrayLong() { return Read().Split(' ').Select(s => long.Parse(s)).ToArray(); }
    }
}