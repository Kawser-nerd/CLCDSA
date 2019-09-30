using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;

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

        static int BinarySearch(int x, List<int> xs)
        {
            int N = xs.Count;
            if (N == 0) { return int.MaxValue; }
            int a = 0;
            int b = N - 1;
            if (xs[a] > x) { return xs[0] - 1; }
            if (xs[b] < x) { return int.MaxValue; }
            while (b - a >= 2)
            {
                int i = (a + b) / 2;
                if (xs[i] < x) { a = i; } else { b = i; }
            }
            return xs[b] - 1;
        }
        static int Solve(int H, int W, HashSet<int>[] set, List<int>[] walls)
        {
            int min = H;
            int x = 1;
            int y = 1;
            while (x < H)
            {
                min = Math.Min(BinarySearch(x, walls[y]), min);
                if (y == W) { break; }
                do { ++x; } while (x < H && set[y + 1].Contains(x));
                ++y;
            }
            return min;
        }
        static void Main(string[] args)
        {
            int[] V1 = ReadInts();
            int H = V1[0];
            int W = V1[1];
            int N = V1[2];
            var set = new HashSet<int>[W + 1];
            var walls = new List<int>[W + 1];
            for (int i = 1; i <= W; ++i)
            {
                set[i] = new HashSet<int>();
                walls[i] = new List<int>();
            }
            for (int i = 0; i < N; ++i)
            {
                int[] V2 = ReadInts();
                int X = V2[0];
                int Y = V2[1];
                set[Y].Add(X);
                walls[Y].Add(X);
            }
            for (int i = 1; i <= W; ++i) { walls[i].Sort(); }
            Console.WriteLine(Solve(H, W, set, walls));
        }
    }
}