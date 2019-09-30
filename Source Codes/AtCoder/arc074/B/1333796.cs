using System;
using System.Linq;
using System.Collections.Generic;

public class Program
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine());
        var xs = Console.ReadLine().Split()
            .Select(x => long.Parse(x))
            .ToArray();
        
        var xss = new []
        {
            xs,
            xs.Reverse().Select(x => -x).ToArray()
        };
        var score = new long[2][];
        var m = 2 * n;
        for (int i = 0; i < 2; ++i)
        {
            score[i] = new long[n + 1];
            score[i][0] = xss[i].Take(n).Sum();
            var dic = xss[i].Take(n)
                .GroupBy(x => x)
                .ToDictionary(x => x.Key, x => x.Count());
            var pbag = new SortedDictionary<long, int>(dic);
            for (int j = n; j < m; ++j)
            {
                if (pbag.ContainsKey(xss[i][j]))
                {
                    ++pbag[xss[i][j]];
                }
                else
                {
                    pbag[xss[i][j]] = 1;
                }

                var min = pbag.Keys.First();
                if (pbag[min] == 1)
                {
                    pbag.Remove(min);
                }
                else
                {
                    --pbag[min];
                }
                score[i][j - n + 1] = score[i][j - n] + xss[i][j] - min;
            }
        }
        Array.Reverse(score[1]);
        
        Console.WriteLine(Enumerable.Zip(score[0], score[1], (i, j) => i + j).Max());
    }
}