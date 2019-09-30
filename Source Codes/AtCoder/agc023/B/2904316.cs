using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;
using static System.Math;
class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        char[][] map = Enumerable.Repeat(0, n).Select(_ => Console.ReadLine().ToArray()).ToArray();
        //[x][y][??]
        bool[][][] isSame = Enumerable.Repeat(0, n).Select(_ => Enumerable.Repeat(0, n).Select(__ => new bool[n]).ToArray()).ToArray();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    isSame[i][j][k] = map[i][j] == map[(i + k) % n][(n + j - k) % n];
                }
            }
        }
        bool[][] isAllSame = Enumerable.Repeat(0, n).Select(_ => Enumerable.Repeat(true, n).ToArray()).ToArray();
        //????
        for (int i = 0; i < n; i++)
        {
            //????????
            for (int j = 0; j < n; j++)
            {
                //???
                for (int k = 0; k < n; k++)
                {
                    if (!isSame[(i + k) % n][k][j])
                    {
                        isAllSame[i][j] = false;
                        break;
                    }
                }
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!isAllSame[(i + j) % n][n - (j + 1)]) goto end;
            }
            count++;
            end:;
        }
        Console.WriteLine(count * n);
    }
}