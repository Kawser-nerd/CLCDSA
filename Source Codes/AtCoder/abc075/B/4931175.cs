using System;
using System.Linq;

namespace B___Minesweeper
{
    class Program
    {
        struct Sharp
        {
            public int i;
            public int j;
        }

        static void Main(string[] args)
        {
            var H_W = Console.ReadLine().Split();
            var H = int.Parse(H_W[0]);
            var W = int.Parse(H_W[1]);

            var Si = Enumerable.Range(1, H).Select(_ => Console.ReadLine()).SelectMany(x => x).ToArray();
            var sharp = new Sharp[Si.Count(x => x == '#')];
            var grid = Enumerable.Repeat('0', H * W).ToArray();

            for (int i = 0, cnt = 0; i < H * W; i++)
                if (Si[i] == '#')
                {
                    sharp[cnt].i = i / W;
                    sharp[cnt].j = i % W;
                    cnt++;
                }

            for (int i = 0; i < H * W; i++)
                foreach (var s in sharp)
                {
                    if (s.i == i / W & s.j == i % W)
                    {
                        grid[i] = '#';
                        break;
                    }
                    else if (Math.Abs(i / W - s.i) <= 1 & Math.Abs(i % W - s.j) <= 1)
                        grid[i]++;
                }

            for (int i = 0; i < H; i++)
            {
                for (int j = 0; j < W; j++)
                    Console.Write(grid[W * i + j]);
                Console.WriteLine();
            }

        }
    }
}