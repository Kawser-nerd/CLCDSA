using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
using System.IO;

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

        static Tuple<long, long> Convert(Tuple<long, long> tuple, long a)
        {
            if (a > tuple.Item2) { return null; }
            long min = (tuple.Item1 + a - 1) / a * a;
            long max = tuple.Item2 / a * a;
            if (min > max) { return null; }
            return new Tuple<long, long>(min, max + a - 1);
        }

        static Tuple<long, long> Solve(long[] A)
        {
            var tuple1 = new Tuple<long, long>(2, 2);
            foreach (long a in A.Reverse())
            {
                var tuple2 = Convert(tuple1, a);
                if (tuple2 != null)
                {
                    tuple1 = tuple2;
                }
                else
                {
                    return null;
                }
            }
            return tuple1;
        }

        static void Main(string[] args)
        {
            int K = ReadInt();
            long[] A = ReadLongs();
            var ans = Solve(A);
            if (ans != null)
            {
                Console.WriteLine("{0} {1}", ans.Item1, ans.Item2);
            }
            else
            {
                Console.WriteLine(-1);
            }
        }
    }
}