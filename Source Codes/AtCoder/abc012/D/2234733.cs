using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;
class P
{
    
    static void Main()
    {
        int[] nm = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int[][] map = Enumerable.Repeat(0, nm[0]).Select(x => Enumerable.Repeat(int.MaxValue / 10, nm[0]).ToArray()).ToArray();
        for (int i = 0; i < nm[1]; i++)
        {
            int[] abt = Console.ReadLine().Split().Select(int.Parse).ToArray();
            map[abt[0] - 1][abt[1] - 1] = abt[2];
            map[abt[1] - 1][abt[0] - 1] = abt[2];
        }
        for (int i = 0; i < map.Length; i++)
        {
            map[i][i] = 0;
        }
        bool flag = true;
        while (flag)
        {
            flag = false;
            for (int i = 0; i < map.Length; i++)
            {
                for (int j = 0; j < map.Length; j++)
                {
                    for (int k = 0; k < map.Length; k++)
                    {
                        if (map[i][j] > map[i][k] + map[k][j])
                        {
                            flag = true;
                            map[i][j] = map[i][k] + map[k][j];
                            map[j][i] = map[i][k] + map[k][j];
                        }
                    }
                }
            }
        }
        Console.WriteLine(map.Min(x => x.Max()));
    }
}