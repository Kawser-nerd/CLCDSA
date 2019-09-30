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

        static int Solve(string s)
        {
            int min = int.MaxValue;
            for (char c = 'a'; c <= 'z'; ++c)
            {
                int cnt;
                char[] S = s.ToArray();
                for (cnt = 0; S.Any(x => x != S[0]); ++cnt)
                {
                    char[] T = new char[S.Length - 1];
                    for (int i = 0; i < T.Length; ++i)
                    {
                        T[i] = (S[i] == c || S[i + 1] == c) ? c : S[i];
                    }
                    S = T;
                }
                min = Math.Min(cnt, min);
            }
            return min;
        }
        static void Main(string[] args)
        {
            Console.WriteLine(Solve(Read()));
        }
    }
}