using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
using System.IO;

namespace AtCoder
{
    class Point
    {
        public readonly int x;
        public readonly int y;
        public Point(int[] args)
        {
            x = args[0];
            y = args[1];
        }
    }
    class Program
    {
        private static string Read() { return Console.ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }

        private static int Solve(List<Point> r1, IEnumerable<Point> b1)
        {
            int count = 0;
            foreach (Point blue in b1.OrderBy(blue => blue.x))
            {
                var r2 = r1.Where(red => red.x < blue.x && red.y < blue.y).OrderByDescending(red => red.y);
                if (r2.Count() > 0)
                {
                    r1.Remove(r2.First());
                    ++count;
                }
            }
            return count;
        }
        static void Main(string[] args)
        {
            int N = ReadInt();
            var r = new List<Point>(N);
            var b = new List<Point>(N);
            for (int i = 0; i < N; ++i) { r.Add(new Point(ReadInts())); }
            for (int i = 0; i < N; ++i) { b.Add(new Point(ReadInts())); }
            Console.WriteLine(Solve(r, b));
        }
    }
}