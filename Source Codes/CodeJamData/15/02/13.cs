using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;

namespace ProblemB
{
    public static class _
    {
        public static T[] Times<T>(this int count, Func<T> f) { return Enumerable.Repeat(0, count).Select(x => f()).ToArray(); }
    }

    public class ProblemB
    {
        Queue<Queue<string>> chunks = new Queue<Queue<string>>();
        void ReadChunks(TextReader tr) { string l; while ((l = tr.ReadLine()) != null) chunks.Enqueue(new Queue<string>(l.Split(' '))); }
        string rc() { var q = chunks.Peek(); if (q.Count == 1) chunks.Dequeue(); return q.Dequeue(); }
        int ri() { return int.Parse(rc()); }
        long rlong() { return long.Parse(rc()); }
        double rd() { return double.Parse(rc(), CultureInfo.InvariantCulture); }
        string rline() { return string.Join(" ", chunks.Dequeue()); }
        void swap<T>(ref T a, ref T b) { var x = a; a = b; b = x; }

        static void Main(string[] args) { new ProblemB().Run(); }

        void Run()
        {
            using (var sr = new StreamReader("B-small-attempt0.in"))
            using (var sw = new StreamWriter("out.txt"))
            {
                ReadChunks(sr);

                var tCase = ri();

                for (var tiCase = 1; tiCase <= tCase; ++tiCase)
                {
                    sw.WriteLine("Case #{0}: {1}", tiCase, Solve());
                }
            }
        }

        private int[][] f;

        private Tuple<int, int> UpTo(int n, int max)
        {
            if (max >= n)
                return Tuple.Create(n, 0);

            for (int i = 1; i < f[n].Length; i++)
            {
                if (f[n][i] <= max)
                    return Tuple.Create(f[n][i], i);
            }

            return null;
        }

        private string Solve()
        {
            if (f == null)
            {
                f = new int[1001][];
                for (int i = 1; i <= 1000; i++)
                {
                    var div = new List<int>(new[]{i});
                    for (int j = 2; j <= 33 && j*j <= i; j++)
                        div.Add(i / j + i % j);
                    f[i] = div.ToArray();
                }
            }

            int D = ri();
            var P = D.Times(ri);
            var min = 1000;

            for (int iMax = 1; iMax <= 1000; iMax++)
            {
                int maxFound = 0;
                int total = 0;

                foreach (var p in P)
                {
                    var ut = UpTo(p, iMax);
                    if (ut == null)
                    {
                        total = maxFound = 1000;
                        break;
                    }
                    maxFound = Math.Max(maxFound, ut.Item1);
                    total += ut.Item2;
                }
                total += maxFound;
                min = Math.Min(min, total);
            }

            return min.ToString();
        }
    }
}
