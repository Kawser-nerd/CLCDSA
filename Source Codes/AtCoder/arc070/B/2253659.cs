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

        static bool Needed(int N, int K, long[] A, int i)
        {
            bool[] dp1 = new bool[K];
            dp1[0] = true;
            foreach (int j in Enumerable.Range(0, N).Where(j => j != i))
            {
                bool[] dp2 = new bool[K];
                for (int k = 0; k < K; ++k)
                {
                    if (dp1[k])
                    {
                        dp2[k] = true;
                        if (k + A[j] < K) { dp2[k + A[j]] = true; }
                    }
                }
                dp1 = dp2;
            }
            return Enumerable.Range(0, K).Any(j => dp1[j] && j + A[i] >= K);
        }
        static int Solve(int N, int K, long[] A)
        {
            Array.Sort(A);
            int min = 0;
            int max = N - 1;
            if ( Needed(N, K, A, min)) { return 0; }
            if (!Needed(N, K, A, max)) { return N; }
            while (max - min > 1)
            {
                int med = (min + max) / 2;
                if (Needed(N, K, A, med)) { max = med; } else { min = med; }
            }
            return max;
        }
        static void Main(string[] args)
        {
            int[] v1 = ReadInts();
            long[] A = ReadLongs();
            Console.WriteLine(Solve(v1[0], v1[1], A));
        }
    }
}