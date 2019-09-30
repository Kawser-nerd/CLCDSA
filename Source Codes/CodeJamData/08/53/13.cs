using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace A
{
    class Program
    {
        static int M, N;
        static int[,] grid;
        static int[][] dirs = new int[][] { new[] { 1, 0 }, new[] { -1, 0 }, new[] { 1, 1 }, new[] { 1, -1 }, new[] { -1, 1 }, new[] { -1, -1 } };
        static void fillseats(int x, int y, int add)
        {
            grid[y, x] += add;
            for (int i = 0; i < 6; i++)
            {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                if (nx >= 0 && nx < N && ny >= 0 && ny < M)
                    grid[ny, nx] += add;
            }
        }
        static int fill(int x, int y, int total, int prev)
        {
            if (y >= M)
            {
                y = 0;
                x++;
                prev = -1;
            }
            if (x >= N)
                return total;
            int max = total;
            if (prev == -1 || prev == 1)
            {
                if (grid[y, x] == 0)
                {
                    fillseats(x, y, 1);
                    max = Math.Max(max, fill(x, y + 1, total + 1, 1));
                    fillseats(x, y, -1);
                }
                else if (prev==1)
                {
                    max = Math.Max(max, fill(x, y + 1, total, -1));

                }
            }
            if (prev == -1 || prev == 0)
            {
                if (grid[y, x] != 0)
                    max = Math.Max(max, fill(x, y + 1, total, -1));
                else
                    max = Math.Max(max, fill(x, y + 1, total, 0));
            }
            return max;
        }
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(args[0]);
            int C = int.Parse(sr.ReadLine());
            for (int t = 1; t <= C; t++)
            {
                string[] split = sr.ReadLine().Split();
                M = int.Parse(split[0]);
                N = int.Parse(split[1]);
                grid = new int[M, N];
                for (int i = 0; i < M; i++)
                {
                    string s = sr.ReadLine();
                    for (int j = 0; j < N; j++)
                    {
                        if (s[j] == 'x')
                            grid[i, j] = 100;
                    }
                }
                int rtn = fill(0, 0, 0, -1);
                Console.WriteLine("Case #{0}: {1}", t, rtn);
            }
        }
    }
}
