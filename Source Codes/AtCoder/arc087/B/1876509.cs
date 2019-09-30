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

        private static HashSet<int> Points(IEnumerable<int> steps)
        {
            var set1 = new HashSet<int>() { 0 };
            foreach (int step in steps)
            {
                var set2 = new HashSet<int>();
                foreach (int p in set1)
                {
                    set2.Add(p - step);
                    set2.Add(p + step);
                }
                set1 = set2;
            }
            return set1;
        }

        private static bool Solve(string s, int x, int y)
        {
            var steps = new List<int>();
            int step = 0;
            foreach (char c in s)
            {
                switch (c)
                {
                case 'F':
                    ++step;
                    break;
                case 'T':
                    steps.Add(step);
                    step = 0;
                    break;
                }
            }
            steps.Add(step);
            var xs = new List<int>();
            var ys = new List<int>();
            for (int i = 1; i < steps.Count; ++i)
            {
                if (i % 2 == 0) { xs.Add(steps[i]); }
                else            { ys.Add(steps[i]); }
            }
            return Points(xs).Contains(x - steps[0]) && Points(ys).Contains(y);
        }
        
        static void Main(string[] args)
        {
            string s = Read();
            int[] points = ReadInts();
            Console.WriteLine(Solve(s, points[0], points[1]) ? "Yes" : "No");
        }
    }
}