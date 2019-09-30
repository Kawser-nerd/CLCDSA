using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Remoting.Messaging;
using System.Web;

namespace Competitive
{
    // ??????
    internal class Solution
    {
        public int H, W;
        public char[,] M, MI;
        public int[] DX = new int[] {1, 0, -1, 0};
        public int[] DY = new int[] {0, 1, 0, -1};
        public bool success;

        public void Run()
        {
            // Input
            H = 10;
            W = 10;

            MI = new char[H, W];
            for (int y = 0; y < H; y++)
            {
                var line = Console.ReadLine();
                for (int x = 0; x < W; x++)
                    MI[y, x] = line[x];
            }

            success = false;
            for (int y = 0; y < H; y++)
            for (int x = 0; x < W; x++)
                DFSRun(y, x);

            Console.WriteLine(success ? "YES" : "NO");

        }

        public void DFSRun(int ay, int ax)
        {
            {
                M = new char[H, W];
                for (int y = 0; y < H; y++)
                for (int x = 0; x < W; x++)
                    M[y, x] = MI[y, x];
                M[ay, ax] = 'o';
            }

            for (int sy = 0; sy < H; sy++)
            for (int sx = 0; sx < W; sx++)
                if (M[sy, sx] == 'o')
                {
                    DFS(sy, sx);

                    for (int y = 0; y < H; y++)
                    for (int x = 0; x < W; x++)
                        if (M[y, x] != 'x')
                            return;

                    success = true;
                    return; // 1???DFS?????
                }
        }

        public void DFS(int y, int x)
        {
            if (M[y, x] == 'x') return;
            M[y, x] = 'x';
            for (int i = 0; i < 4; i++)
            {
                int yy = y + DY[i];
                int xx = x + DX[i];
                if (0 <= yy && yy < H && 0 <= xx && xx < W)
                    DFS(yy, xx);
            }
        }


        // common ----------

        internal static class Input
        {
            public static string ReadString()
            {
                string line = Console.ReadLine();
                return line;
            }

            public static int ReadInt()
            {
                string line = Console.ReadLine();
                return int.Parse(line);
            }

            public static int[] ReadIntArray()
            {
                string line = Console.ReadLine();
                return line.Split(' ').Select(int.Parse).ToArray();
            }

            public static long ReadLong()
            {
                string line = Console.ReadLine();
                return long.Parse(line);
            }

            public static long[] ReadLongArray()
            {
                string line = Console.ReadLine();
                return line.Split(' ').Select(long.Parse).ToArray();
            }

            public static double[] ReadDoubleArray()
            {
                string line = Console.ReadLine();
                return line.Split(' ').Select(double.Parse).ToArray();
            }
        }

        internal class Program
        {
            public static void Main(string[] args)
            {
                var s = new Solution();
                s.Run();
            }
        }

    }
}