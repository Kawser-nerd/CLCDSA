using System;
using System.Collections.Generic;
using System.Linq;

namespace ABC107_B
{
    class Program
    {
        static void Main(string[] args)
        {
            var HW = Console.ReadLine().Split().Select(int.Parse).ToArray();
            var H = HW[0];
            var W = HW[1];

            var grid = new char[H, W];
            var ignoreRow = new List<int>();
            for (int i = 0; i < H; i++)
            {
                var line = Console.ReadLine();
                if (!line.Contains("#")) ignoreRow.Add(i);
                for (int j = 0; j < line.Length; j++)
                {
                    grid[i, j] = line[j];
                }
            }

            var ignoreCol = new List<int>();
            for (int j = 0; j < W; j++)
            {
                var sharpcnt = 0;
                for (int i = 0; i < H; i++)
                {
                    if (grid[i, j] == '#') sharpcnt++;
                }
                if (sharpcnt == 0) ignoreCol.Add(j);
            }

            for (int i = 0; i < H; i++)
            {
                if (ignoreRow.Contains(i)) continue;
                for (int j = 0; j < W; j++)
                {
                    if (ignoreCol.Contains(j)) continue;
                    Console.Write(grid[i, j]);
                }
                Console.WriteLine();
            }
        }
    }
}