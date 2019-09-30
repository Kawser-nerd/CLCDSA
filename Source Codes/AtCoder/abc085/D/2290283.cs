using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AtCoder
{
    class Program
    {
        private const int MODULO = 1000000007;
        private static string Read() { return Console.ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }

        static int Div(int a, int b)
        {
            return (a + b - 1) / b;
        }
        static int Solve(int N, int H, Tuple<int, int>[] katanas)
        {
            int max = katanas.Max(katana => katana.Item1);
            Array.Sort(katanas, (a, b) => b.Item2 - a.Item2);
            int i;
            for (i = 0; i < N && katanas[i].Item2 > max; ++i)
            {
                H -= katanas[i].Item2;
                if (H <= 0) { return i + 1; }
            }
            return i + Div(H, max);
        }
        static void Main(string[] args)
        {
            int[] v1 = ReadInts();
            int N = v1[0];
            int H = v1[1];
            var katanas = new Tuple<int, int>[N];
            for (int i = 0; i < N; ++i)
            {
                int[] v2 = ReadInts();
                katanas[i] = new Tuple<int, int>(v2[0], v2[1]);
            }
            Console.WriteLine(Solve(N, H, katanas));
        }
    }
}