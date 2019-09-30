using System;
using System.Collections.Generic;
using System.Linq;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = ReadArrayInt();
            var N = input[0];
            var K = input[1];
            var A = ReadArrayLong();
            var can = false;
            if (A.Contains(K)) can = true;
            else if (A.Max() < K) can = false;
            else
            {
                var g = A[0];
                for (int i = 1; i < N; i++) g = Gcd(g, A[i]);
                if (K % g == 0) can = true;
            }

            Console.WriteLine(can ? "POSSIBLE" : "IMPOSSIBLE");
            Console.ReadLine();
        }

        static long Gcd(long a, long b) { if (b == 0) return a; return Gcd(b, a % b); }

        static string Read() { return Console.ReadLine(); }
        static int ReadInt() { return int.Parse(Read()); }
        static long ReadLong() { return long.Parse(Read()); }
        static int[] ReadArrayInt() { return Read().Split(' ').Select(s => int.Parse(s)).ToArray(); }
        static long[] ReadArrayLong() { return Read().Split(' ').Select(s => long.Parse(s)).ToArray(); }
    }
}