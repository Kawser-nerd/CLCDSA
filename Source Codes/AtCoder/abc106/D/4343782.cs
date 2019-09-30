using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_106
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nmq = ReadInts();
            int n = nmq[0];
            int m = nmq[1];
            int q = nmq[2];
            int[,] pat = new int[n, n];
            for(int i = 0; i < m; i++)
            {
                int[] lr = ReadInts();
                int l = lr[0]-1;
                int r = lr[1]-1;
                pat[l, r]++;
            }
            for(int i = 1; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if (j + i >= n) break;
                    pat[j, j + i] += pat[j, j + i - 1] + pat[j + 1, j + i];
                    if (i > 1)
                    {
                        pat[j, j + i] -= pat[j + 1, j + i - 1];
                    }
                }
            }
            int[] res = new int[q];
            for(int i = 0; i < q; i++)
            {
                int[] pq = ReadInts();
                res[i] = pat[pq[0] - 1, pq[1] - 1];
            }
            for (int i = 0; i < q; i++) Console.WriteLine(res[i]);
        }

        private static string Read() { return Console.ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }
    }
}