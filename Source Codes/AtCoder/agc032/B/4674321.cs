using System;
using System.Collections.Generic;
using System.Linq;

public class Hello
{
    private const ulong MOD9 = 1000000007;

    public static void Main()
    {
        var n = int.Parse(Console.ReadLine());

        var answer = new List<Tuple<int, int>>();

        if (n % 2 == 1)
        {
            for (var i = 1; i < n; ++i)
                answer.Add(Tuple.Create(i, n));
            --n;
        }

        for (var i = 1; i < n; ++i)
        {
            var t = n - i + 1;
            for (var j = i + 1; j <= n; ++j)
            {
                if (j != t)
                    answer.Add(Tuple.Create(i, j));
            }
        }

        Console.WriteLine(answer.Count);
        foreach (var t in answer)
            Console.WriteLine($"{t.Item1} {t.Item2}");
    }
}