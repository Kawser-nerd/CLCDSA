using System;
using System.Collections.Generic;
using System.Linq;

class Solution
{
    static void Main()
    {
        var vals = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        var n = vals[0];
        var m = vals[1];
        var p = Console.ReadLine().Split(' ').Select(int.Parse).ToList();
        p.Insert(0, 0);
        var link = Enumerable.Range(0, n + 1).Select(_ => new List<int>()).ToArray();
        for (int i = 0; i < m; i++)
        {
            vals = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            link[vals[0]].Add(vals[1]);
            link[vals[1]].Add(vals[0]);
        }

        var sets = new List<HashSet<int>>();
        var visit = new bool[n + 1];

        for (int i = 1; i <= n; i++)
        {
            if (visit[i])
            {
                continue;
            }

            var currents = new HashSet<int> { i };
            var set = new List<int> { i };
            while (currents.Count > 0)
            {
                var next = new HashSet<int>();
                foreach (var cur in currents)
                {
                    visit[cur] = true;
                }
                foreach (var cur in currents)
                {
                    next.UnionWith(link[cur].Where(x => !visit[x]));
                }

                set.AddRange(next);
                currents = next;
            }
            sets.Add(new HashSet<int>(set));
        }

        int result = 0;
        foreach (var set in sets)
        {
            var list = set.Select(i => p[i]).ToList();
            foreach (var i in list)
            {
                if (set.Contains(i))
                {
                    result++;
                }
            }
        }

        Console.WriteLine(result);
    }
}