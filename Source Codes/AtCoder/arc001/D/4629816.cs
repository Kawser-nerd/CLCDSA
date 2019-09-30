using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_C
{
    class _001
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int[,] grid = new int[8, 8];
            for(int i =0; i < 8; i++)
            {
                string s = Read();
                for (int j = 0; j < 8; j++)
                {
                    grid[i, j] = s[j] == 'Q' ? 1 : 0;
                }
            }
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (grid[i,j] == 1)
                    {
                        for (int k = 0; k < 8; k++)
                        {
                            for (int l = 0; l < 8; l++)
                            {
                                if (k == i && l == j) continue;
                                if (k == i || l == j
                                    || Abs(k - i) == Abs(l - j))
                                {
                                    if (grid[k, l] == 1)
                                    {
                                        WriteLine("No Answer");
                                        return;
                                    }
                                    grid[k, l] = -1;
                                }
                            }
                        }
                    }
                }
            }
            if (!DFS(ref grid, 0))
            {
                WriteLine("No Answer");
                return;
            }
            for (int i = 0; i < 8; i++)
            {
                for(int j = 0; j < 8; j++)
                {
                    Write(grid[i, j] == 1 ? 'Q' : '.');
                }
                WriteLine();
            }
        }

        static bool DFS(ref int[,] grid, int h)
        {
            if (h == 8) return true;

            for(int i = 0; i < 8; i++)
            {
                if (grid[h, i] == 0)
                {
                    //WriteLine(h + " " + i);
                    int[,] prev = new int[8, 8];
                    for(int k = 0; k < 8; k++)
                    {
                        for(int l = 0; l < 8; l++)
                        {
                            prev[k, l] = grid[k, l];
                            //Write(grid[k, l] == 0 ? '.' : 'x');
                            if (k == h || l == i
                                    || Abs(k - h) == Abs(l - i))
                            {
                                grid[k, l] = -1;
                            }
                        }
                        //WriteLine();
                    }
                    grid[h, i] = 1;
                    if (DFS(ref grid, h + 1)) return true;
                    grid = prev;
                }
                else if (grid[h, i] == 1)
                {
                    if (DFS(ref grid, h + 1)) return true;
                }
            }
            return false;
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