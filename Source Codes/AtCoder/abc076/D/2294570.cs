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

        static double Solve(int N, int[] T, int[] V)
        {
            double y = 0;
            double v1 = 0;
            for (int i = 0; i < N; ++i)
            {
                double V1 = V[i];
                double V2 = (i + 1) < N ? V[i + 1] : 0;
                for (int j = 0; j < T[i] * 2; ++j)
                {
                    var limits = new List<double>() { V[i] };
                    double t = T[i] - (j * 0.5 + 0.5);
                    for (int k = i + 1; k < N; ++k)
                    {
                        limits.Add(t + V[k]);
                        t += T[k];
                    }
                    limits.Add(t);
                    double v2 = Math.Min(v1 + 0.5, limits.Min());
                    y += (v1 + v2) * 0.25;
                    v1 = v2;
                }
            }
            return y;
        }
        static void Main(string[] args)
        {
            int N = ReadInt();
            int[] T = ReadInts();
            int[] V = ReadInts();
            Console.WriteLine(Solve(N, T, V));
        }
    }
}