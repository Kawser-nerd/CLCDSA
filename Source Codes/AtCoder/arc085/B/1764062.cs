using System;
using System.Collections.Generic;
using System.Linq;

class Solution
{
    static int n;
    static int z;
    static int w;
    static int[] a;

    static int[][] cache = new int[2][];
    static int GetBest(int index, int player)
    {
        var key = Tuple.Create(index, player);
        if (cache[player][index + 1] >= 0)
        {
            return cache[player][index + 1];
        }

        var best = 0;
        if (player == 1)
        {
            best = int.MaxValue;
        }
        for (int i = index + 1; i < n; i++)
        {
            int diff;
            if (i != n - 1)
            {
                diff = GetBest(i, player ^ 1);
            }
            else
            {
                int enemyNum;
                if (index >= 0)
                {
                    enemyNum = a[index];
                }
                else
                {
                    enemyNum = (player == 1) ? z : w;
                }

                diff = Math.Abs(enemyNum - a.Last());
            }

            if (player == 0)
            {
                best = Math.Max(best, diff);
            }
            else
            {
                best = Math.Min(best, diff);
            }
        }

        cache[player][index + 1] = best;
        return best;
    }

    static void Main()
    {
        var vals = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        n = vals[0];
        z = vals[1];
        w = vals[2];
        a = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();

        for (int i = 0; i < 2; i++)
        {
            cache[i] = Enumerable.Repeat(-1, n + 1).ToArray();
        }
        var result = GetBest(-1, 0);

        Console.WriteLine(result);
    }
}