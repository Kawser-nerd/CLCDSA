using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_C
{
    class _003
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
            int[,] grid = new int[n, m];
            int[] start = new int[2] { 0, 0 };
            int[] goal = new int[2] { 0, 0 };
            for(int i = 0; i < n; i++)
            {
                string s = Read();
                for(int j = 0; j < m; j++)
                {
                    if (s[j] == 's')
                    {
                        start[0] = i;
                        start[1] = j;
                        grid[i, j] = 1000000000;
                    }
                    else if (s[j] == 'g')
                    {
                        goal[0] = i;
                        goal[1] = j;
                        grid[i, j] = 1000000000;
                    }
                    else if (s[j] == '#')
                    {
                        grid[i, j] = -1;
                    }
                    else
                    {
                        grid[i, j] = s[j] - '0';
                    }
                }
            }
            Queue<int[]> checkQueue = new Queue<int[]>();
            checkQueue.Enqueue(new int[2] { start[0], start[1] });
            bool[,] checkVisited = new bool[n, m];
            bool canGoal = false;
            while (checkQueue.Count > 0)
            {
                int[] val = checkQueue.Dequeue();
                if (checkVisited[val[0], val[1]]) continue;

                checkVisited[val[0], val[1]] = true;

                if (val[0] == goal[0] && val[1] == goal[1])
                {
                    canGoal = true;
                    break;
                }

                if (val[0] > 0&&grid[val[0]-1,val[1]]>0)
                {
                    checkQueue.Enqueue(new int[2] { val[0] - 1, val[1] });
                }
                if (val[1] > 0 && grid[val[0], val[1]-1] > 0)
                {
                    checkQueue.Enqueue(new int[2] { val[0], val[1]-1 });
                }
                if (val[0]+1 <n && grid[val[0] + 1, val[1]] > 0)
                {
                    checkQueue.Enqueue(new int[2] { val[0] +1, val[1] });
                }
                if (val[1] + 1 < m && grid[val[0], val[1]+1] > 0)
                {
                    checkQueue.Enqueue(new int[2] { val[0], val[1] + 1 });
                }
            }
            if (!canGoal)
            {
                WriteLine(-1);
                return;
            }

            double thres = 0.0000000001;
            double bottom = 0;
            double top = 10;
            while (top - bottom > thres)
            {
                //WriteLine(bottom + " " + top);
                double mid = (bottom + top) * 0.5;
                Queue<int[]> queue = new Queue<int[]>();
                queue.Enqueue(new int[3] { start[0], start[1], 0 });
                bool[,] visited = new bool[n, m];
                bool ok = false;
                while (queue.Count > 0)
                {
                    int[] val = queue.Dequeue();
                    if (visited[val[0], val[1]]) continue;

                    visited[val[0], val[1]] = true;

                    if (val[0] == goal[0] && val[1] == goal[1])
                    {
                        ok = true;
                        break;
                    }
                    double rate = Pow(0.99, val[2] + 1);

                    if (val[0] > 0
                        && rate * grid[val[0] - 1, val[1]] >= mid)
                    {
                        queue.Enqueue(new int[3]
                        { val[0] - 1, val[1], val[2] + 1 });
                    }
                    if (val[1] > 0
                        && rate * grid[val[0], val[1]-1] >= mid)
                    {
                        queue.Enqueue(new int[3]
                        { val[0], val[1]-1, val[2] + 1 });
                    }
                    if (val[0]+1<n
                        && rate * grid[val[0] + 1, val[1]] >= mid)
                    {
                        queue.Enqueue(new int[3]
                        { val[0] + 1, val[1], val[2] + 1 });
                    }
                    if (val[1]+1<m
                        && rate * grid[val[0], val[1] + 1] >= mid)
                    {
                        queue.Enqueue(new int[3]
                        { val[0], val[1]+1, val[2] + 1 });
                    }
                }
                if (ok)
                {
                    bottom = mid;
                }
                else
                {
                    top = mid;
                }
            }
            WriteLine(bottom);
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