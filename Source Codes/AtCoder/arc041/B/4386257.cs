using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_B
{
    class _041
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
            int[,] after = new int[n, m];
            for(int i = 0; i < n; i++)
            {
                string s = Read();
                for(int j = 0; j < m; j++)
                {
                    after[i, j] = s[j] - '0';
                }
            }
            int[,] res = new int[n, m];
            int x1 = 0, x2 = m - 1, y1 = 0, y2 = n - 1;
            while (x1 + 1 < x2 && y1 + 1 < y2)
            {
                for (int i = 0; i < n; i++)
                {
                    if (after[i,x1] > 0)
                    {
                        res[i, x1 + 1] += after[i, x1];
                        Down(ref after, x1 + 1, i, after[i, x1]);
                    }
                }
                for (int i = 0; i < n; i++)
                {
                    if (after[i, x2] > 0)
                    {
                        res[i, x2 - 1] += after[i, x2];
                        Down(ref after, x2 - 1, i, after[i, x2]);
                    }
                }
                for (int i = 0; i < m; i++)
                {
                    if (after[y1,i] > 0)
                    {
                        res[y1+1,i] += after[y1,i];
                        Down(ref after, i, y1+1, after[y1, i]);
                    }
                }
                for (int i = 0; i < m; i++)
                {
                    if (after[y2, i] > 0)
                    {
                        res[y2 - 1, i] += after[y2, i];
                        Down(ref after, i, y2 - 1, after[y2, i]);
                    }
                }
                x1++;
                x2--;
                y1++;
                y2--;
            }

            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    Write(res[i, j]);
                }
                WriteLine();
            }
        }

        static void Down(ref int[,] grid, int cX, int cY, int val)
        {
            grid[cY, cX + 1] -= val;
            grid[cY, cX - 1] -= val;
            grid[cY+1, cX] -= val;
            grid[cY-1, cX] -= val;
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