using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;
//using static System.Globalization.CultureInfo;

class Program
{
    static void Main(string[] args)
    {
        var nw = Array.ConvertAll(ReadLine().Split(' '), long.Parse);
        var dic = new Dictionary<int, List<int>>();
        for(var i = 0; i < nw[0]; i++)
        {
            var input = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
            if (dic.ContainsKey(input[0]))
                dic[input[0]].Add(input[1]);
            else dic[input[0]] = new List<int> { input[1] };
        }
        var kee = dic.Keys.ToList();
        for (var i = 0; i < kee.Count; i++)
            dic[kee[i]] = dic[kee[i]].OrderByDescending(v => v).ToList();
        var min = kee.Min();
        var keys = Enumerable.Range(0, 4).Select(v => v + min).ToArray();
        foreach (var ke in keys)
        {
            if (!dic.ContainsKey(ke))
                dic[ke] = new List<int>();
        }
        var res = 0L;
        for (var i = 0; i <= nw[0]; i++)
        {
            if (i > dic[keys[0]].Count) break;
            for (var j = 0; j <= nw[0]; j++)
            {
                if (j > dic[keys[1]].Count) break;
                for (var h = 0; h <= nw[0]; h++)
                {
                    if (h > dic[keys[2]].Count) break;
                    for (var k = 0; k <= nw[0]; k++)
                    {
                        if (k > dic[keys[3]].Count) break;
                        var ar = new[] { i, j, h, k };
                        var weight = 0L;
                        var va = 0L;
                        for (var i1 = 0; i1 < 4; i1++)
                        {
                            weight += (long)keys[i1] * ar[i1];
                            va += dic[keys[i1]].Take(ar[i1]).Sum();
                        }
                        if (weight <= nw[1])
                            res = Max(res, va);
                    }
                }
            }
        }
        WriteLine(res);
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}