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

        private static Tuple<int, int> Solve(int A, int B, int C, int D, int E, int F)
        {
            var set = new HashSet<Tuple<int, int>>();
            var queue = new Queue<Tuple<int, int>>();
            var zero = new Tuple<int, int>(0, 0);
            set.Add(zero);
            queue.Enqueue(zero);
            while (queue.Count > 0)
            {
                var t1 = queue.Dequeue();
                int w1 = t1.Item1;
                int s1 = t1.Item2;
                foreach (var t2 in new[] { new Tuple<int, int>(w1 + 100 * A, s1),
                                           new Tuple<int, int>(w1 + 100 * B, s1),
                                           new Tuple<int, int>(w1, s1 + C),
                                           new Tuple<int, int>(w1, s1 + D) })
                {
                    int w2 = t2.Item1;
                    int s2 = t2.Item2;
                    if (!set.Contains(t2) && w2 * E >= s2 * 100 && w2 + s2 <= F)
                    {
                        set.Add(t2);
                        queue.Enqueue(t2);
                    }
                }
            }
            return set.OrderByDescending(t => (double)t.Item2 / (t.Item1 + t.Item2)).ElementAt(0);
        }
        static void Main(string[] args)
        {
            int[] values = ReadInts();
            var tuple = Solve(values[0],
                              values[1],
                              values[2],
                              values[3],
                              values[4],
                              values[5]);
            Console.WriteLine("{0} {1}", tuple.Item1 + tuple.Item2, tuple.Item2);
        }
    }
}