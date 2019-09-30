using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;

namespace ProblemD
{
    public static class _
    {
        public static T[] Times<T>(this int count, Func<T> f) { return Enumerable.Repeat(0, count).Select(x => f()).ToArray(); }
    }

    public class ProblemD
    {
        Queue<Queue<string>> chunks = new Queue<Queue<string>>();
        void ReadChunks(TextReader tr) { string l; while ((l = tr.ReadLine()) != null) chunks.Enqueue(new Queue<string>(l.Split(' '))); }
        string rc() { var q = chunks.Peek(); if (q.Count == 1) chunks.Dequeue(); return q.Dequeue(); }
        int ri() { return int.Parse(rc()); }
        void swap<T>(ref T a, ref T b) { var x = a; a = b; b = x; }

        static void Main(string[] args) { new ProblemD().Run(); }

        void Run()
        {
            using (var sr = new StreamReader("D-large.in"))
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

        private string Answer(bool isPossible) { return isPossible? "GABRIEL" : "RICHARD"; }

        private string Solve()
        {
            int X = ri(), R = ri(), C = ri();

            if (R < C)
                swap(ref R, ref C);

            switch (X)
            {
                case 1:
                    return Answer(true);
                case 2:
                    return Answer((R*C)%2 == 0);
                case 3:
                    return Answer(R >= 3 && C >= 2 && (R*C)%3 == 0);
                case 4:
                    return Answer(R >= 4 && C >= 3 && (R*C)%4 == 0);
                case 5:
                    return Answer((R*C)%5 == 0 && ((R >= 10 && C == 3) || (R >= 5 && C >= 4)));
                case 6:
                    return Answer(R >= 6 && C >= 4 && (R * C) % 6 == 0);
            }

            return Answer(false);
        }
    }
}
