using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_B
{
    class _031
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            bool[,] grid = new bool[10, 10];
            int cnt = 0;
            for(int i = 0; i < 10; i++)
            {
                string s = Read();
                for(int j = 0; j < 10; j++)
                {
                    if (s[j] == 'o')
                    {
                        cnt++;
                        grid[i, j] = true;
                    }
                }
            }

            for(int i = 0; i < 10; i++)
            {
                for(int j = 0; j < 10; j++)
                {
                    bool[,] visited = new bool[10, 10];
                    visited[i, j] = true;
                    Queue<int[]> queue = new Queue<int[]>();
                    queue.Enqueue(new int[2] { i, j });
                    int tmp = 0;
                    while (queue.Count > 0)
                    {
                        tmp++;
                        int[] yx = queue.Dequeue();
                        int x = yx[1];
                        int y = yx[0];
                        if (y - 1 >= 0 && grid[y - 1, x] && !visited[y - 1, x])
                        {
                            visited[y - 1, x] = true;
                            queue.Enqueue(new int[2] { y - 1, x });
                        }
                        if (y + 1 < 10 && grid[y + 1, x] && !visited[y + 1, x])
                        {
                            visited[y + 1, x] = true;
                            queue.Enqueue(new int[2] { y + 1, x });
                        }
                        if (x - 1 >= 0 && grid[y, x - 1] && !visited[y, x - 1])
                        {
                            visited[y, x - 1] = true;
                            queue.Enqueue(new int[2] { y, x - 1 });
                        }
                        if (x + 1 < 10 && grid[y, x + 1] && !visited[y, x + 1])
                        {
                            visited[y, x + 1] = true;
                            queue.Enqueue(new int[2] { y, x + 1 });
                        }
                    }
                    if (tmp == cnt + 1)
                    {
                        WriteLine("YES");
                        return;
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