using System;
using System.Collections.Generic;
using System.Linq;

class Solution
{
    static void Main()
    {
        var vals = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        int h = vals[0];
        int w = vals[1];
        var n = int.Parse(Console.ReadLine());
        var a = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        var array = new List<int>();
        for(int t = 0; t < a.Length;t++)
        {
            array.AddRange(Enumerable.Repeat(t + 1, a[t]));
        }

        var grid = Enumerable.Range(0, h).Select(_ => new int[w]).ToArray();
        int i = 0;
        bool sw = true;
        for(int y = 0; y < h;y++)
        {
            if (sw)
            {
                for (int x = 0; x < w; x++)
                {
                    grid[y][x] = array[i++];
                }
            }
            else
            {
                for (int x = w-1; x >= 0; x--)
                {
                    grid[y][x] = array[i++];
                }
            }
            sw ^= true;
        }

        foreach (var row in grid)
        {
            Console.WriteLine(string.Join(" ", row));
        }
    }
}