using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

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

        private static IEnumerable<Tuple<int, int>> SolveNegatively(int N, long[] a)
        {
            var list = new List<Tuple<int, int>>();
            for (int i = N - 1; i > 0; --i)
            {
                if (a[i - 1] > a[i])
                {
                    a[i - 1] += a[i];
                    list.Add(new Tuple<int, int>(i, i - 1));
                }
            }
            return list;
        }

        private static IEnumerable<Tuple<int, int>> SolvePositively(int N, long[] a)
        {
            var list = new List<Tuple<int, int>>();
            for (int i = 0; i < N - 1; ++i)
            {
                if (a[i] > a[i + 1])
                {
                    a[i + 1] += a[i];
                    list.Add(new Tuple<int, int>(i, i + 1));
                }
            }
            return list;
        }

        private static IEnumerable<Tuple<int, int>> Solve(int N, long[] a)
        {
            long min = int.MaxValue;
            long max = int.MinValue;
            int mini = 0;
            int maxi = 0;
            for (int i = 0; i < N; ++i)
            {
                if (a[i] < min)
                {
                    min = a[i];
                    mini = i;
                }
                if (a[i] > max)
                {
                    max = a[i];
                    maxi = i;
                }
            }
            if (max <= 0)
            {
                return SolveNegatively(N, a);
            }
            else if (min >= 0)
            {
                return SolvePositively(N, a);
            }
            else
            {
                var list = new List<Tuple<int, int>>();
                if (Math.Abs(min) > Math.Abs(max))
                {
                    for (int i = 0; i < N; ++i)
                    {
                        if (a[i] > 0)
                        {
                            a[i] += min;
                            list.Add(new Tuple<int, int>(mini, i));
                        }
                    }
                    return Enumerable.Concat(list, SolveNegatively(N, a));
                }
                else
                {
                    for (int i = 0; i < N; ++i)
                    {
                        if (a[i] < 0)
                        {
                            a[i] += max;
                            list.Add(new Tuple<int, int>(maxi, i));
                        }
                    }
                    return Enumerable.Concat(list, SolvePositively(N, a));
                }
            }
        }

        static void Main(string[] args)
        {
            int N = ReadInt();
            long[] a = ReadLongs();
            var tuples = Solve(N, a);
            Console.WriteLine(tuples.Count());
            foreach (var tuple in tuples)
            {
                Console.WriteLine("{0} {1}", tuple.Item1 + 1, tuple.Item2 + 1);
            }
        }
    }
}