using System;
using System.Collections.Generic;
using System.Linq;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = ReadArrayInt();
            var H = input[0];
            var W = input[1];
            var board = new int[H, W];
            for (int i = 0; i < H; i++)
            {
                input = ReadArrayInt();
                for (int j = 0; j < W; j++)
                {
                    board[i, j] = input[j];
                }
            }
            var ans = new List<int[]>();
            for (int i = 0; i < H; i++)
            {
                for (int j = 0; j < W; j++)
                {
                    if (i == H - 1 && j == W - 1) break;
                    if (j != W - 1)
                    {
                        if (board[i, j] % 2 != 0)
                        {
                            board[i, j]--;
                            board[i, j + 1]++;
                            ans.Add(new int[] { i + 1, j + 1, i + 1, j + 2 });
                        }
                    }
                    else
                    {
                        if (board[i, j] % 2 != 0)
                        {
                            board[i, j]--;
                            board[i + 1, j]++;
                            ans.Add(new int[] { i + 1, j + 1, i + 2, j + 1 });
                        }
                    }
                }
            }

            Console.WriteLine(ans.Count);
            foreach(var a in ans)
            {
                Console.WriteLine(a[0] + " " + a[1] + " " + a[2] + " " + a[3]);
            }

            Console.WriteLine();
            Console.ReadLine();
        }

        static string Read() { return Console.ReadLine(); }
        static int ReadInt() { return int.Parse(Read()); }
        static long ReadLong() { return long.Parse(Read()); }
        static int[] ReadArrayInt() { return Read().Split(' ').Select(s => int.Parse(s)).ToArray(); }
        static long[] ReadArrayLong() { return Read().Split(' ').Select(s => long.Parse(s)).ToArray(); }
    }
}