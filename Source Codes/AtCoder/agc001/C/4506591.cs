using System;
using System.IO;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using System.Numerics;
using System.Diagnostics;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using static System.Math;
using MethodImplOptions = System.Runtime.CompilerServices.MethodImplOptions;
using MethodImplAttribute = System.Runtime.CompilerServices.MethodImplAttribute;

class P
{
    static void Main()
    {
        var nk = Console.ReadLine().Split().Select(int.Parse).ToList();
        List<int>[] neighbours = Enumerable.Repeat(0, nk[0]).Select(_ => new List<int>()).ToArray();
        List<Tuple<int, int>> edges = new List<Tuple<int, int>>();
        for (int i = 0; i < nk[0] - 1; i++)
        {
            var ab = Console.ReadLine().Split().Select(x => int.Parse(x) - 1).ToList();
            neighbours[ab[0]].Add(ab[1]);
            neighbours[ab[1]].Add(ab[0]);
            edges.Add(new Tuple<int, int>(ab[0], ab[1]));
        }

        Dictionary<int, int>[] indexes = neighbours.Select(x => x.Select((y, z) => new Tuple<int, int>(y, z)).ToDictionary(y => y.Item1, y => y.Item2)).ToArray();
        List<int>[][] datas = neighbours.Select(x => new List<int>[x.Count]).ToArray();

        Func<int, int, List<int>> dfs = null;
        dfs = (x, from) =>
        {
            List<int> ret = new List<int>() { 1 };
            for (int i = 0; i < datas[x].Length; i++)
            {
                var dest = neighbours[x][i];
                if (dest == from) continue;
                var v = datas[x][i] != null ? datas[x][i] : (datas[x][i] = dfs(dest, x));
                for (int j = 1; j <= v.Count; j++)
                {
                    if(j >= ret.Count) ret.Add(0);
                    ret[j] += v[j - 1];
                }
            }
            return ret;
        };
        List<int>[] dfsRes = new List<int>[nk[0]];
        for (int i = 0; i < nk[0]; i++) dfsRes[i] = dfs(i, -1);

        int res = int.MaxValue;
        if (nk[1] % 2 == 0)
        {
            res = Enumerable.Range(0, nk[0]).Min(x => dfsRes[x].Skip(nk[1] / 2 + 1).Sum());
        }
        else
        {
            res = edges.Min(x => datas[x.Item1][indexes[x.Item1][x.Item2]].Skip(nk[1] / 2 + 1).Sum() + datas[x.Item2][indexes[x.Item2][x.Item1]].Skip(nk[1] / 2 + 1).Sum());
        }
        Console.WriteLine(res);
    }
}