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

        private static double[] Solve(int N, Point[] points)
        {
            var probs = new double[N];
            for (int i = 0; i < N; ++i)
            {
                var a = new List<double>();
                var b = new List<double>();
                for (int j = 0; j < N; ++j)
                {
                    if (i != j)
                    {
                        Point p1 = points[i];
                        Point p2 = points[j];
                        double rad = Math.Atan2(p2.y - p1.y, p2.x - p1.x);
                        a.Add(rad);
                        b.Add((rad < 0) ? rad + Math.PI * 2 : rad);
                    }
                }
                a.Sort();
                b.Sort();
                double theta = Math.Min(a.Last() - a.First(), b.Last() - b.First());
                probs[i] = Math.Max((Math.PI - theta) / (Math.PI * 2), 0);
            }
            return probs;
        }

        static void Main(string[] args)
        {
            int N = ReadInt();
            var points = new Point[N];
            for (int i = 0; i < N; ++i)
            {
                points[i] = new Point(ReadInts());
            }
            foreach (double prob in Solve(N, points))
            {
                Console.WriteLine(prob);
            }
        }
    }
}