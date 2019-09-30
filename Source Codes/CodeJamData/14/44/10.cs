using System;
using System.Collections.Generic;
using System.Linq;

class D
{
    Tuple<int, int> Solve(int N, List<string> S)
    {
        HashSet<string>[] list = new HashSet<string>[4];
        for (int i = 0; i < list.Length; i++)
            {
                list[i] = new HashSet<string>();
            }
        int x = 0;
        int y = 1;
        foreach (int pattern in Enumerable.Range(0, 1 << (2 * S.Count)))
        {
            bool flg = true;
            for (int i = 0; i < list.Length; i++) list[i].Clear();
            for (int i = 0; i < S.Count; i++)
            {
                var target = (pattern & (3 << (i * 2))) >> (i * 2);
                if (target >= N) { flg = false; break; }
                foreach (int j in Enumerable.Range(0, S[i].Length + 1))
                {
                    list[target].Add(S[i].Substring(0, j));
                }
            }
            if (!flg) continue;
            var result = Enumerable.Range(0, 4).Sum(i => list[i].Count);
            if (x == result) y++;
            else if (x < result)
            {
                x = result;
                y = 1;
            }
        }
        return Tuple.Create(x, y);
    }

    static IEnumerable<string> Output()
    {
        var line = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        var ret = new D().Solve(line[1], Enumerable.Range(0,line[0]).Select(i=>Console.ReadLine()).ToList());
        yield return ret.Item1 + " " + ret.Item2;
    }
    static void Main() { foreach (var i in Enumerable.Range(1, Convert.ToInt32(Console.ReadLine()))) Console.WriteLine("Case #{0}: {1}", i, string.Join(Environment.NewLine, Output().ToArray())); }

}