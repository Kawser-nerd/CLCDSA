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

        static int Solve(int N, int[] P)
        {
            int count = 0;
            for (int i = 0; i < N; ++i)
            {
                if (P[i] == i + 1)
                {
                    if (i + 1 < N)
                    {
                        int tmp = P[i];
                        P[i] = P[i + 1];
                        P[i + 1] = tmp;
                    }
                    ++count;
                }
            }
            return count;
        }

        static void Main(string[] args)
        {
            int N = ReadInt();
            Console.WriteLine(Solve(N, ReadInts()));
        }
    }
}