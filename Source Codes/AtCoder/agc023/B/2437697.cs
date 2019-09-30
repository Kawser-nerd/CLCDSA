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

        static bool Good(int N, string[] A, int k)
        {
            for (int i = 0; i < N; ++i)
            {
                for (int j = 0; j < N; ++j)
                {
                    if (A[(i + k) % N][j] != A[(j + k) % N][i]) { return false; }
                }
            }
            return true;
        }
        static int Solve(int N, string[] A)
        {
            int count = 0;
            for (int i = 0; i < N; ++i)
            {
                if (Good(N, A, i)) { count += N; }
            }
            return count;
        }
        static void Main(string[] args)
        {
            int N = ReadInt();
            var A = new string[N];
            for (int i = 0; i < N; ++i) { A[i] = Read(); }
            Console.WriteLine(Solve(N, A));
        }
    }
}