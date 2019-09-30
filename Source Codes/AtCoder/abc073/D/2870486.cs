using System;
using System.Linq;
using System.Collections.Generic;
using static System.Math;

class P
{
    static void Main()
    {
        int[] nmr = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int n = nmr[0];
        int m = nmr[1];
        int r = nmr[2];
        int[][] map = Enumerable.Repeat(0, n).Select(_ => Enumerable.Repeat(int.MaxValue / 2, n).ToArray()).ToArray();
        int[] rs = Console.ReadLine().Split().Select(int.Parse).OrderBy(x => x).ToArray();
        for (int i = 0; i < m; i++)
        {
            int[] abc = Console.ReadLine().Split().Select(int.Parse).ToArray();
            map[abc[0] - 1][abc[1] - 1] = abc[2];
            map[abc[1] - 1][abc[0] - 1] = abc[2];
        }
        bool flag = true;
        while (flag)
        {
            flag = false;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    for (int k = 0; k < n; k++)
                    {
                        if (map[i][j] > map[i][k] + map[k][j])
                        {
                            map[i][j] = map[i][k] + map[k][j];
                            flag = true;
                        }
                    }
                }
            }
        }

        long min = long.MaxValue;
        do
        {
            long res = 0;
            for (int i = 1; i < rs.Length; i++)
            {
                res += map[rs[i] - 1][rs[i - 1] - 1];
            }
            min = Min(min, res);
        } while (NextPermutation(rs));
        Console.WriteLine(min);
    }
    private static bool NextPermutation(int[] numList)
    {
        var largestIndex = -1;
        for (var i = numList.Length - 2; i >= 0; i--)
        {
            if (numList[i] < numList[i + 1])
            {
                largestIndex = i;
                break;
            }
        }

        if (largestIndex < 0) return false;

        var largestIndex2 = -1;
        for (var i = numList.Length - 1; i >= 0; i--)
        {
            if (numList[largestIndex] < numList[i])
            {
                largestIndex2 = i;
                break;
            }
        }

        var tmp = numList[largestIndex];
        numList[largestIndex] = numList[largestIndex2];
        numList[largestIndex2] = tmp;

        for (int i = largestIndex + 1, j = numList.Length - 1; i < j; i++, j--)
        {
            tmp = numList[i];
            numList[i] = numList[j];
            numList[j] = tmp;
        }

        return true;
    }
}