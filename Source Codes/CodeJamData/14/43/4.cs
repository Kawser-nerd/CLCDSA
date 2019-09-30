using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Globalization;
using System.Numerics;

namespace C
{
    class Program
    {
        static bool[][] MAP;
        static int W, H;

        static bool dfs(int y, int x, int dir)
        {

            if (y < 0 || y >= H || x < 0 || x >= W)
                return false;

            if (MAP[y][x])
                return false;

            //Console.WriteLine("y:{0} x:{1}", y, x);
            MAP[y][x] = true;

            if (y == H - 1)
                return true;

            int[] seq_x = { -1, 0, 1, 0 };
            int[] seq_y = { 0, 1, 0, -1 };

            for (int d = dir - 1; d <= dir + 2; d++)
            {
                int mod = (d + 8) % 4;
                if (dfs(y + seq_y[mod], x + seq_x[mod], mod))
                    return true;
            }
            return false;
        }

        static int Solve()
        {
            int total = 0;
            for (int i = 0; i < W; i++)
            {
                if (!MAP[0][i])
                    if(dfs(0, i, 1))
                        total++;
            }
            return total;
        }

        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

            int T = int.Parse(Console.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                string[] line = Console.ReadLine().Split();
                W = int.Parse(line[0]);
                H = int.Parse(line[1]);
                int B = int.Parse(line[2]);

                MAP = new bool[H][];
                for(int i = 0; i < H; i++)
                    MAP[i] = new bool[W];

                for (int i = 0; i < B; i++)
                {
                    line = Console.ReadLine().Split();
                    int X0 = int.Parse(line[0]);
                    int Y0 = int.Parse(line[1]);
                    int X1 = int.Parse(line[2]);
                    int Y1 = int.Parse(line[3]);

                    if (X0 > X1) { int tmp = X1; X1 = X0; X0 = tmp; }
                    if (Y0 > Y1) { int tmp = Y1; Y1 = Y0; Y0 = tmp; }

                    for (int x = X0; x <= X1; x++)
                        for (int y = Y0; y <= Y1; y++)
                            MAP[y][x] = true;
                }

                Console.WriteLine("Case #{0}: {1}", t, Solve());
            }
        }
    }
}
