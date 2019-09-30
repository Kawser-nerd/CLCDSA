using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;

namespace AtCoder
{
    class Program
    {
        private static string Read() { return Console.ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }

        static long Gcd(long a, long b)
        {
            return (a < b) ? Gcd(b, a)
                 : (b > 0) ? Gcd(b, a % b)
                           : a;
        }

        static long Gcd(IEnumerable<long> values)
        {
            return values.Aggregate(Gcd);
        }

        static void Main(string[] args)
        {
            int N = ReadInt();
            long[] A = ReadLongs();
            Console.WriteLine(Gcd(A));
        }
    }
}