using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_C
{
    class _005
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int[] hw = ReadInts();
            int h = hw[0];
            int w = hw[1];
            int[,] grid = new int[h, w];
            int[] start = new int[2];
            int[] goal = new int[2];
            int[,] map = new int[h, w];
            for (int i = 0;i< h; i++)
            {
                string s = Read();
                for(int j = 0; j < w; j++)
                {
                    if (s[j] == 's')
                    {
                        start[0] = i;
                        start[1] = j;
                    }
                    else if (s[j] == 'g')
                    {
                        goal[0] = i;
                        goal[1] = j;
                    }
                    else if (s[j] == '#')
                    {
                        grid[i, j] = -1;
                    }
                    map[i, j] = -1;
                }
            }
            Queue<int[]> pos = new Queue<int[]>();
            pos.Enqueue(new int[3] { start[0], start[1], 2 });
            while (pos.Count > 0)
            {
                int[] val = pos.Dequeue();
                if (map[val[0], val[1]] >= val[2]) continue;
                map[val[0], val[1]] = val[2];
                if (val[0] == goal[0] && val[1] == goal[1])
                {
                    WriteLine("YES");
                    return;
                }
                if (val[0] > 0)
                {
                    if (grid[val[0]-1, val[1]] == -1)
                    {
                        pos.Enqueue(new int[3] { val[0]-1, val[1], val[2]-1 });
                    }
                    else
                    {
                        pos.Enqueue(new int[3] { val[0]-1, val[1], val[2] });
                    }
                }
                if (val[0]+1<h)
                {
                    if (grid[val[0]+1, val[1]] == -1)
                    {
                        pos.Enqueue(new int[3] { val[0]+1, val[1], val[2] - 1 });
                    }
                    else
                    {
                        pos.Enqueue(new int[3] { val[0]+1, val[1], val[2] });
                    }
                }
                if (val[1] > 0)
                {
                    if (grid[val[0], val[1]-1] == -1)
                    {
                        pos.Enqueue(new int[3] { val[0], val[1]-1, val[2] - 1 });
                    }
                    else
                    {
                        pos.Enqueue(new int[3] { val[0], val[1]-1, val[2] });
                    }
                }
                if (val[1] +1<w)
                {
                    if (grid[val[0], val[1] + 1] == -1)
                    {
                        pos.Enqueue(new int[3] { val[0], val[1] + 1, val[2] - 1 });
                    }
                    else
                    {
                        pos.Enqueue(new int[3] { val[0], val[1] +1, val[2] });
                    }
                }
            }
            WriteLine("NO");
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