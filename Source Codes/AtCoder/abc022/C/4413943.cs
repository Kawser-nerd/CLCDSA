using System;
using System.Linq;
using System.Numerics;
using System.Collections.Generic;
using static System.Math;
using System.Collections;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;


class P
{
    static void Main()
    {
        var nm = Console.ReadLine().Split().Select(int.Parse).ToList();
        int[][] dists = Enumerable.Repeat(0, nm[0]).Select(_ => Enumerable.Repeat(int.MaxValue / 2, nm[0]).ToArray()).ToArray();
        for (int i = 0; i < nm[0]; i++) dists[i][i] = 0;
        List<int> Neighbours = new List<int>();
        for (int i = 0; i < nm[1]; i++)
        {
            var uvl = Console.ReadLine().Split().Select(int.Parse).ToList();
            if (uvl[0] == 1)Neighbours.Add(uvl[1] - 1);
            dists[uvl[0] - 1][uvl[1] - 1] = uvl[2];
            dists[uvl[1] - 1][uvl[0] - 1] = uvl[2];
        }

        bool flag = true;
        while (flag)
        {
            flag = false;
            for (int i = 1; i < nm[0]; i++)
                for (int j = 1; j < nm[0]; j++)
                    for (int k = 1; k < nm[0]; k++)
                        if (dists[i][j] > dists[i][k] + dists[k][j])
                        {
                            flag = true;
                            dists[i][j] = dists[i][k] + dists[k][j];
                        }
        }

        int res = int.MaxValue;
        for (int i = 0; i < Neighbours.Count; i++)
            for (int j = 0; j < Neighbours.Count; j++)
                if (i != j) res = Min(res, dists[Neighbours[i]][Neighbours[j]] + dists[0][Neighbours[i]] + dists[0][Neighbours[j]]);

        Console.WriteLine(res >= int.MaxValue / 2 ? -1 : res);
    }
}