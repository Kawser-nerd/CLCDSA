using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AtCoder
{
    class Program
    {
        private const int MODULO = 1000000007;
        private static string Read() { return Console.ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }

        static int Solve(int N, long[] A)
        {
            long min = long.MaxValue;
            long max = 0;
            long[] mins = new long[N - 1];
            long[] maxs = new long[N - 1];
            for (int i = 0; i < N - 1; ++i)
            {
                int j = N - 1 - i;
                min = Math.Min(A[i], min);
                max = Math.Max(A[j], max);
                mins[i] = min;
                maxs[j - 1] = max;
            }
            var dict = new Dictionary<long, int>();
            foreach (long a in A)
            {
                if (!dict.ContainsKey(a)) { dict[a] = 0; }
                ++dict[a];
            }
            var range = Enumerable.Range(0, N - 1).Max(i => maxs[i] - mins[i]);
            var tuples = new HashSet<Tuple<long, long>>();
            for (int i = 0; i < N - 1; ++i)
            {
                if (maxs[i] - mins[i] == range) { tuples.Add(new Tuple<long, long>(mins[i], maxs[i])); }
            }
            int count = 0;
            foreach (var tuple in tuples)
            {
                count += Math.Min(dict[tuple.Item1], dict[tuple.Item2]);
            }
            return count;
        }
        static void Main(string[] args)
        {
            int[] v = ReadInts();
            long[] A = ReadLongs();
            Console.WriteLine(Solve(v[0], A));
        }
    }
}