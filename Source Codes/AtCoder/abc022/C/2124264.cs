using System;
using System.Linq;
using System.Collections.Generic;
class P
{
    static void Main()
    {
        int[] nm = Console.ReadLine().Split().Select(int.Parse).ToArray();

        int[][] map = Enumerable.Repeat(0, nm[0]).Select(_ => Enumerable.Repeat(int.MaxValue / 3, nm[0]).ToArray()).ToArray();

        for (int i = 0; i < nm[1]; i++)
        {
            int[] uvl = Console.ReadLine().Split().Select(int.Parse).ToArray();
            map[uvl[0] - 1][uvl[1] - 1] = uvl[2];
            map[uvl[1] - 1][uvl[0] - 1] = uvl[2];
        }

        bool flag = true;
        int inc = 0;
        while (flag)
        {
            flag = false;
            for (int i = 1; i < map.Length; i++)
            {
                for (int j = 1; j < map.Length; j++)
                {
                    for (int k = i; k < map.Length; k++)
                    {
                        if (i != j && j != k && k != i)
                        {
                            //i-j-k < i-k
                            if (map[i][j] + map[j][k] < map[i][k])
                            {
                                flag = true;
                                map[i][k] = map[i][j] + map[j][k];
                                map[k][i] = map[i][j] + map[j][k];
                            }
                        }
                    }
                }
            }
            inc++;
        }
        int min = int.MaxValue;
        for (int i = 1; i < map.Length; i++)
        {
            for (int j = 1; j < map.Length; j++)
            {
                if(i != j)
                {
                    min = Math.Min(min, map[0][i] + map[i][j] + map[j][0]);
                }
            }
        }
        if (100000000 < min)
        {
            min = -1;
        }
        Console.WriteLine(min);
    }
}