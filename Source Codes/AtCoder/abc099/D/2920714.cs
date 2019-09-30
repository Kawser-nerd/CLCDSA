using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using static System.Math;

class P
{
    static void Main()
    {
        //???
        //???
        //
        int[] nc = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int[][] d = Enumerable.Repeat(0, nc[1]).Select(_ => Console.ReadLine().Split().Select(int.Parse).ToArray()).ToArray();
        int[][] c = Enumerable.Repeat(0, nc[0]).Select(_ => Console.ReadLine().Split().Select(int.Parse).ToArray()).ToArray();

        int[][] cold = Enumerable.Repeat(0, 3).Select(x => new int[nc[1]]).ToArray();
        for (int i = 0; i < nc[0]; i++)
        {
            for (int j = 0; j < nc[0]; j++)
            {
                for (int k = 0; k < nc[1]; k++)
                {
                    cold[(i + j) % 3][k] += d[c[i][j] - 1][k];
                }
            }
        }
        int min = int.MaxValue;
        for (int i = 0; i < nc[1]; i++)
        {
            for (int j = 0; j < nc[1]; j++)
            {
                if (i == j) continue;
                for (int k = 0; k < nc[1]; k++)
                {
                    if (i == k) continue;
                    if (j == k) continue;

                    min = Min(min, cold[0][i] + cold[1][j] + cold[2][k]);
                }
            }
        }
        Console.WriteLine(min);
    }
}