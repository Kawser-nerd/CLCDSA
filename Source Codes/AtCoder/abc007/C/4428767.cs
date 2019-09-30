using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

public class Program
{
    static void Main()
    {
        var input = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
        var row = input[0];
        var col = input[1];

        var start = Console.ReadLine().Split().Select(x => int.Parse(x) - 1).ToArray();
        var end = Console.ReadLine().Split().Select(x => int.Parse(x) - 1).ToArray();

        var grid = new string[row];
        for (int i = 0; i < row; i++)
        {
            grid[i] = Console.ReadLine();
        }

        var memo = new int[row][].Select(x => new int[col].Select(y => int.MaxValue).ToArray()).ToArray();
        var queue = new Queue<string>();
        memo[start[0]][start[1]] = 0;
        queue.Enqueue($"{start[0]} {start[1]}");

        while (queue.Count != 0)
        {
            var point = queue.Dequeue().Split().Select(x => int.Parse(x)).ToArray();
            var r = point[0];
            var c = point[1];

            if (memo[r + 1][c] == int.MaxValue && grid[r + 1][c] == '.')
            {
                memo[r + 1][c] = memo[r][c] + 1;
                queue.Enqueue($"{r + 1} {c}");
            }

            if (memo[r - 1][c] == int.MaxValue && grid[r - 1][c] == '.')
            {
                memo[r - 1][c] = memo[r][c] + 1;
                queue.Enqueue($"{r - 1} {c}");
            }

            if (memo[r][c + 1] == int.MaxValue && grid[r][c + 1] == '.')
            {
                memo[r][c + 1] = memo[r][c] + 1;
                queue.Enqueue($"{r} {c + 1}");
            }

            if (memo[r][c - 1] == int.MaxValue && grid[r][c - 1] == '.')
            {
                memo[r][c - 1] = memo[r][c] + 1;
                queue.Enqueue($"{r} {c - 1}");
            }
        }

        Console.WriteLine(memo[end[0]][end[1]]);
    }
}