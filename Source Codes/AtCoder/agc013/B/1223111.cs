using System;
using System.Linq;
using System.Collections.Generic;

public class Program
{
    public static void Main()
    {
        var nm = Console.ReadLine().Split()
            .Select(x => int.Parse(x))
            .ToArray();
        var n = nm[0];
        var m = nm[1];
        var edgesQuery =
            from i in Enumerable.Range(1, m)
            let vu = Console.ReadLine().Split()
                .Select(x => int.Parse(x))
                .ToArray()
            select new[] { vu, vu.Reverse() } into dual
            from e in dual
            group e.Last() by e.First() into g
            select g;
        var edges = edgesQuery.ToDictionary(x => x.Key, x => x.ToArray());

        var path = new LinkedList<int>(new[] { 1 });
        var nodes = new HashSet<int>() { 1 };
        var end = new[] { 1, 1 };
        var length = 1;
        for (int i = 0; i < 2; ++i)
        {
            var addToPath = i == 0
                ? (Action<int>)(x => path.AddFirst(x))
                : (Action<int>)(x => path.AddLast(x));

            while (true)
            {
                end[i] = edges[end[i]].FirstOrDefault(x => !nodes.Contains(x));
                if (end[i] == 0)
                {
                    break;
                }

                nodes.Add(end[i]);
                addToPath(end[i]);
                ++length;
            }
        }

        Console.WriteLine(length);
        Console.WriteLine(string.Join(" ", path));
    }
}