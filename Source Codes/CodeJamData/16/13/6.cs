using System;
using System.Collections.Generic;
using System.Linq;

class C
{
    int Solve(List<int> F)
    {
        F = F.Select(f => f - 1).ToList();
        var dict = new Dictionary<int, int>();
        int max = 0;
        for (int i = 0; i < F.Count; i++)
        {
            var used = new bool[F.Count];
            int count = 0;
            for (int f = i; ; f = F[f])
            {
                count++;
                used[f] = true;
                var next = F[f];
                if (f == F[next])
                {
                    dict[f] = Math.Max(count, dict.ContainsKey(f) ? dict[f] : 0);
                    break;
                }
                if (used[next])
                {
                    if (next == i)
                    {
                        max = Math.Max(max, count);
                    }
                    break;
                }
            }
        }
        return Math.Max(max, dict.Sum(kv => kv.Value));
    }

    static IEnumerable<string> Output()
    {
        Console.ReadLine();
        yield return new C().Solve(Console.ReadLine().Split(' ').Select(int.Parse).ToList()).ToString();
    }
    static void Main() { foreach (var i in Enumerable.Range(1, Convert.ToInt32(Console.ReadLine()))) Console.WriteLine("Case #{0}: {1}", i, string.Join(Environment.NewLine, Output().ToArray())); }
}