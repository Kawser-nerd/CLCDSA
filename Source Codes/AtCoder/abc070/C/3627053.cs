using System;
using System.Collections.Generic;
using System.Linq;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = ReadInt();
            var ans = ReadLong();
            for (int i = 1; i < N; i++)
            {
                var tmp = ReadLong();
                ans = Lcm(ans, tmp);
            }

            Console.WriteLine(ans);
            Console.ReadLine();
        }

        static long Gcd(long a, long b) { if (b == 0) return a; return Gcd(b, a % b); }
        static long Lcm(long a, long b)
        {
            var gcd = Gcd(a, b);
            var tmpA = a / gcd;
            var tmpB = b / gcd;

            return tmpA * tmpB * gcd;
        }

        static string Read() { return Console.ReadLine(); }
        static int ReadInt() { return int.Parse(Read()); }
        static long ReadLong() { return long.Parse(Read()); }
        static int[] ReadArrayInt() { return Read().Split(' ').Select(s => int.Parse(s)).ToArray(); }
        static long[] ReadArrayLong() { return Read().Split(' ').Select(s => long.Parse(s)).ToArray(); }
    }
}