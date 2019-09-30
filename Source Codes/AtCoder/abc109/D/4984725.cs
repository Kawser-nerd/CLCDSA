using System;
using System.Linq;
using System.Collections.Generic;

using E = System.Linq.Enumerable;

public class Program
{
    public static void Main()
    {
        var hw = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
        var h = hw[0];
        var w = hw[1];
        var grid = new int[h + 2][];
        grid[0] = grid[h + 1] = E.Repeat(-1, w + 2).ToArray();
        for (int i = 1; i < grid.Length - 1; i++)
        {
            grid[i] = Console.ReadLine().Split().Select(x => int.Parse(x)).Prepend(int.MinValue).Append(int.MinValue).ToArray();
        }

        var k = 0;
        var steps = new System.Text.StringBuilder();
        var sy = 1;
        var sx = 1;
        var dy = new [] { 0, 1, 0, -1 };
        var dx = new [] { 1, 0, -1, 0 };
        var d = 0;
        while (true)
        {
            if (grid[sy + dy[d]][sx + dx[d]] < 0)
            {
                d = (d + 1) % dy.Length;
                if (grid[sy + dy[d]][sx + dx[d]] < 0)
                {
                    break;
                }
            }

            var ty = sy + dy[d];
            var tx = sx + dx[d];
            if (grid[sy][sx] % 2 == 1)
            {
                k++;
                steps.AppendLine($"{sy} {sx} {ty} {tx}");
                grid[ty][tx]++;
            }
            grid[sy][sx] = int.MinValue;
            sy = ty;
            sx = tx;
        }
        Console.WriteLine(k);
        Console.Write(steps);
    }
}

static class EnumerableExtension
{
    public static IEnumerable<T> Prepend<T>(this IEnumerable<T> source, T element)
    {
        yield return element;
        foreach (var x in source)
        {
            yield return x;
        }
    }

    public static IEnumerable<T> Append<T>(this IEnumerable<T> source, T element)
    {
        foreach (var x in source)
        {
            yield return x;
        }
        yield return element;
    }
}