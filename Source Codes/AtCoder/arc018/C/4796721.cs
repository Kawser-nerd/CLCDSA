using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_C
{
    class _018
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nm = ReadInts();
            int n = nm[0];
            int m = nm[1];
            int[] xap = ReadInts();
            int x = xap[0];
            int a = xap[1];
            int p = xap[2];
            if (a % p == 0)
            {
                int x2 = x % p;
                if (x > x2)
                {
                    WriteLine(2 * (n - 1));
                }
                else {
                    WriteLine(0);
                }
                return;
            }

            int[,] grid = new int[n, m];
            grid[0, 0] = x;
            int[] all = new int[n * m];
            all[0] = grid[0, 0];
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    if (i == 0 && j == 0) continue;

                    if (j == 0)
                    {
                        grid[i, j] = (grid[i - 1, m - 1] + a) % p;
                    }
                    else
                    {
                        grid[i, j] = (grid[i, j - 1] + a) % p;
                    }
                    all[i * m + j] = grid[i, j];
                }
            }
            Array.Sort(all);
            var rowDict = new Dictionary<int, int>();
            for(int i = 0; i < n * m; i++)
            {
                rowDict.Add(all[i], i / m);
            }
            int[] rowCnts = new int[n];
            long res = 0;
            for(int i = 0; i < m; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    long val = Abs(j - rowDict[grid[j, i]]);
                    val += Abs(i - rowCnts[rowDict[grid[j, i]]]);
                    rowCnts[rowDict[grid[j, i]]]++;
                    res += val;
                }
            }
            WriteLine(res);
        }

        private static string Read() { return ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }
    }
}