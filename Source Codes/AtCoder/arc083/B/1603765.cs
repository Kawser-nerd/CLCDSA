using System;
using System.Collections.Generic;
using System.Linq;

class Solution
{
    // ??????????????????
    // ??????????????????????
    // ??????????????-1???
    public static long GetMinDistanceSum(long[][] dist)
    {
        long sum = 0;
        var first = 0;
        var n = dist.Length;

        // ?ij?????????k??????????????????
        for (int i = first; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                long d = long.MaxValue;
                for (int k = first; k < n; k++)
                {
                    if (i == k || j == k)
                    {
                        continue;
                    }
                    if (dist[i][k] == long.MaxValue || dist[k][j] == long.MaxValue)
                    {
                        continue;
                    }
                    d = Math.Min(d, dist[i][k] + dist[k][j]);
                }
                // ?????????????
                if (dist[i][j] < d)
                {
                    sum += dist[i][j];
                }
                // ????????????????
                else if (dist[i][j] > d)
                {
                    return -1;
                }
            }
        }
        return sum;
    }

    static void Main()
    {
        var n = int.Parse(Console.ReadLine());
        var graph = new long[n][];
        for (int i = 0; i < n; i++)
        {
            graph[i] = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
        }
        var sum = GetMinDistanceSum(graph);
        Console.WriteLine(sum);
    }
}