using System;
using System.Collections.Generic;
using System.Linq;

class Solution
{
    static int GetSum(int[][] table, int x0, int y0, int x1, int y1)
    {
        var maxX = Math.Max(x0, x1);
        var maxY = Math.Max(y0, y1);
        var minX = Math.Min(x0, x1) - 1;
        var minY = Math.Min(y0, y1) - 1;

        int sum = table[maxY][maxX];
        if (minX >= 0)
        {
            sum -= table[maxY][minX];
        }
        if (minY >= 0)
        {
            sum -= table[minY][maxX];
        }
        if (minX >= 0 && minY >= 0)
        {
            sum += table[minY][minX];
        }

        return sum;
    }

    static void Main()
    {
        var vals = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        int n = vals[0];
        int k = vals[1];
        var blackCount = Enumerable.Range(0, k).Select(_ => new int[k]).ToArray();
        var whiteCount = Enumerable.Range(0, k).Select(_ => new int[k]).ToArray();
        for (int i = 0; i < n; i++)
        {
            var v = Console.ReadLine().Split(' ').ToArray();
            var x = int.Parse(v[0]) % (2 * k);
            var y = int.Parse(v[1]) % (2 * k);
            var color = v[2][0];
            var isBlack = color == 'B';

            if (x >= k && y >= k)
            {
                x -= k;
                y -= k;
            }
            else if (x >= k)
            {
                x -= k;
                isBlack ^= true;
            }
            else if (y >= k)
            {
                y -= k;
                isBlack ^= true;
            }

            if (isBlack)
            {
                blackCount[y][x]++;
            }
            else
            {
                whiteCount[y][x]++;
            }
        }

        // ????
        for (int y = 0; y < k; y++)
        {
            for (int x = 1; x < k; x++)
            {
                blackCount[y][x] += blackCount[y][x - 1];
                whiteCount[y][x] += whiteCount[y][x - 1];
            }
        }

        // ????
        for (int x = 0; x < k; x++)
        {
            for (int y = 1; y < k; y++)
            {
                blackCount[y][x] += blackCount[y - 1][x];
                whiteCount[y][x] += whiteCount[y - 1][x];
            }
        }

        int max = 0;
        int min = int.MaxValue;
        for (int x = 0; x < k; x++)
        {
            for (int y = 0; y < k; y++)
            {
                int satisfied = 0;
                // ????(x-1,y-1)???
                if (x > 0 && y > 0)
                {
                    satisfied += GetSum(blackCount, 0, 0, x - 1, y - 1);
                }
                // (x,y)???????
                satisfied += GetSum(blackCount, x, y, k - 1, k - 1);
                // (x,y-1)???????
                if (y > 0)
                {
                    satisfied += GetSum(whiteCount, x, y - 1, k - 1, 0);
                }
                // ????(x-1,y)???
                if (x > 0)
                {
                    satisfied += GetSum(whiteCount, 0, k - 1, x - 1, y);
                }

                max = Math.Max(max, satisfied);
                min = Math.Min(min, satisfied);
            }
        }

        max = Math.Max(max, n - min);
        Console.WriteLine(max);
    }
}