using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int[][] map = Enumerable.Range(1, 4).Select(_ => Console.ReadLine().Split().Select(int.Parse).ToArray()).ToArray();
        for (int i = 1; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (map[i][j] == map[i - 1][j] || map[j][i] == map[j][i - 1])
                {
                    Console.WriteLine("CONTINUE");
                    return;
                }
            }
        }
        Console.WriteLine("GAMEOVER");
    }
}