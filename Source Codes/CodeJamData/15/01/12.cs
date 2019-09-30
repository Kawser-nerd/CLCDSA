using System;
using System.Collections.Generic;
using System.Globalization;
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
            var Smax = ri();
            var s = rc();
            int total = 0;
            int add = 0;

            for (int i = 0; i <= Smax; i++)
            {
                int a = s[i] - '0';
                if (i > total)
                {
                    add += i - total;
                    total += i - total;
                }

                total += a;
            }

            return add.ToString();
        }
    }
}