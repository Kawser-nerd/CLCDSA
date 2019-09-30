using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
using System.IO;

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

        private const int M = 1000000007;

        private static int Solve(int N, string S1, string S2)
        {
            long res = (S1[0] == S2[0]) ? 3 : 6;
            int n1   = (S1[0] == S2[0]) ? 1 : 2;
            for (int i = 1; i < N; ++i)
            {
                int n2 = (S1[i] == S2[i]) ? 1 : 2;
                if (n2 == 1)
                {
                    res *= (n1 == 1) ? 2 : 1;
                }
                else if (S1[i - 1] != S1[i])
                {
                    res *= (n1 == 1) ? 2 : 3;
                }
                res %= M;
                n1 = n2;
            }
            return (int)res;
        }

        static void Main(string[] args)
        {
            int N = ReadInt();
            string S1 = Read();
            string S2 = Read();
            Console.WriteLine(Solve(N, S1, S2));
        }
    }
}