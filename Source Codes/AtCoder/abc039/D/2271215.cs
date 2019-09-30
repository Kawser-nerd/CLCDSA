using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int[] hw = Console.ReadLine().Split().Select(int.Parse).ToArray();
        char[][] map = Enumerable.Repeat(0, hw[0]).Select(_ => Console.ReadLine().ToCharArray()).ToArray();

        char[][] predmap = Enumerable.Repeat(0, hw[0]).Select(_ => Enumerable.Repeat('.',hw[1]).ToArray()).ToArray();
        for (int i = 0; i < hw[0]; i++)
        {
            for (int j = 0; j < hw[1]; j++)
            {
                for (int k = -1; k <= 1; k++)
                {
                    if (i + k < 0 || i + k >= hw[0]) continue;
                    for (int l = -1; l <= 1; l++)
                    {
                        if (j + l < 0 || j + l >= hw[1]) continue;
                        if (map[i + k][j + l] == '.') goto end;
                    }
                }
                predmap[i][j] = '#';
                end:;
            }
        }
        for (int i = 0; i < hw[0]; i++)
        {
            for (int j = 0; j < hw[1]; j++)
            {
                if (map[i][j] == '.') continue;
                for (int k = -1; k <= 1; k++)
                {
                    if (i + k < 0 || i + k >= hw[0]) continue;
                    for (int l = -1; l <= 1; l++)
                    {
                        if (j + l < 0 || j + l >= hw[1]) continue;
                        if (predmap[i + k][j + l] == '#') goto end;
                    }
                }
                Console.WriteLine("impossible");
                return;
                end:;
            }
        }
        Console.WriteLine("possible");
        Console.WriteLine(string.Join("\n", predmap.Select(x => string.Join("", x))));
    }
}