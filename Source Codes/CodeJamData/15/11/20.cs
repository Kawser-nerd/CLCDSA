using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace ProblemA
{
    public static class _
    {
        public static T[] Times<T>(this int count, Func<T> f) { return Enumerable.Repeat(0, count).Select(x => f()).ToArray(); }
    }

    public class ProblemA
    {
        Queue<Queue<string>> chunks = new Queue<Queue<string>>();
        void ReadChunks(TextReader tr) { string l; while ((l = tr.ReadLine()) != null) chunks.Enqueue(new Queue<string>(l.Split(' '))); }
        string rc() { var q = chunks.Peek(); if (q.Count == 1) chunks.Dequeue(); return q.Dequeue(); }
        int ri() { return int.Parse(rc()); }

        static void Main(string[] args) { new ProblemA().Run(); }

        void Run()
        {
            using (var sr = new StreamReader("A-large.in"))
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

        private string Solve()
        {
            var N = ri();
            var m = N.Times(ri);

            long sol1 = 0;
            for (int i = 1; i < N; i++)
            {
                var t = m[i - 1] - m[i];
                if (t > 0)
                    sol1 += t;
            }

            long sol2 = long.MaxValue;
            int maxDiff = 0;
            for (int i = 1; i < N; i++)
                maxDiff = Math.Max(m[i - 1] - m[i], maxDiff);

            long sol2temp = 0;
            for (int i = 1; i < N; i++)
            {
                long d = m[i - 1] - m[i];

                if (d < 0)
                    d = 0;

                var eaten = Math.Min(maxDiff, m[i - 1]);
                sol2temp += eaten;
            }

            sol2 = Math.Min(sol2, sol2temp);


            return string.Format("{0} {1}", sol1, sol2);
        }
    }
}
