using System;
using System.IO;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using System.Numerics;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using static System.Math;
using Debug = System.Diagnostics.Debug;

class P
{
    static void Main()
    {
        var hw = Console.ReadLine().Split().Select(int.Parse).ToList();
        var c = Enumerable.Repeat(0, hw[0]).Select(_ => Console.ReadLine()).ToList();
        int[][] grid = Enumerable.Repeat(0, hw[0]).Select(_ => new int[hw[1]]).ToArray();
        int sy = 0;
        int sx = 0;
        int gy = 0;
        int gx = 0;
        for (int i = 0; i < hw[0]; i++)
        {
            for (int j = 0; j < hw[1]; j++)
            {
                if(c[i][j] == 's')
                {
                    sy = i;
                    sx = j;
                    grid[i][j] = 10;
                }
                if(c[i][j] == 'g')
                {
                    gy = i;
                    gx = j;
                    grid[i][j] = 10;
                }
                if (c[i][j] == '#') grid[i][j] = -1;
                grid[i][j] = c[i][j] - '0';
            }
        }
        //????????????????????????????????????????
        //???????????? ???
        double[][] score = Enumerable.Repeat(0, hw[0]).Select(_ => Enumerable.Repeat(-1.0, hw[1]).ToArray()).ToArray();
        Queue<Tuple<int, int>> queue = new Queue<Tuple<int, int>>();
        queue.Enqueue(new Tuple<int, int>(gy, gx));
        score[gy][gx] = 10.0;
        while (queue.Count > 0)
        {
            var item = queue.Dequeue();
            var curCost = score[item.Item1][item.Item2] * 0.99;
            if (item.Item1 != 0 && score[item.Item1 - 1][item.Item2] < Min(curCost, grid[item.Item1 - 1][item.Item2]))
            {
                queue.Enqueue(new Tuple<int, int>(item.Item1 - 1, item.Item2));
                score[item.Item1 - 1][item.Item2] = Min(curCost, grid[item.Item1 - 1][item.Item2]);
            }
            if (item.Item1 != hw[0] - 1 && score[item.Item1 + 1][item.Item2] < Min(curCost, grid[item.Item1 + 1][item.Item2]))
            {
                queue.Enqueue(new Tuple<int, int>(item.Item1 + 1, item.Item2));
                score[item.Item1 + 1][item.Item2] = Min(curCost, grid[item.Item1 + 1][item.Item2]);
            }
            if (item.Item2 != 0 && score[item.Item1][item.Item2 - 1] < Min(curCost, grid[item.Item1][item.Item2 - 1]))
            {
                queue.Enqueue(new Tuple<int, int>(item.Item1, item.Item2 - 1));
                score[item.Item1][item.Item2 - 1] = Min(curCost, grid[item.Item1][item.Item2 - 1]);
            }
            if (item.Item2 != hw[1] - 1 && score[item.Item1][item.Item2 + 1] < Min(curCost, grid[item.Item1][item.Item2 + 1]))
            {
                queue.Enqueue(new Tuple<int, int>(item.Item1, item.Item2 + 1));
                score[item.Item1][item.Item2 + 1] = Min(curCost, grid[item.Item1][item.Item2 + 1]);
            }
        }
        Console.WriteLine(score[sy][sx] < 0 ? -1 : score[sy][sx]);
    }
}