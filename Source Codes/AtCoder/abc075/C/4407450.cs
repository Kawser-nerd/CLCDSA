using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;
//using static System.Globalization.CultureInfo;

class Program
{
    struct P
    {
        public int index;
        public List<int> ad;
        public P(int index)
        {
            this.index = index;
            ad = new List<int>();
        }
    }
    static void Main(string[] args)
    {
        var nm = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var ab = new int[nm[1]][];
        for (var i = 0; i < nm[1]; i++)
            ab[i] = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var res = 0;
        for (var i = 0; i < nm[1]; i++)
        {
            var ps = new P[nm[0]];
            for (var j = 0; j < nm[0]; j++)
                ps[j] = new P(j);
            for(var j = 0; j < nm[1]; j++)
            {
                if (i == j) continue;
                ps[ab[j][0] - 1].ad.Add(ab[j][1] - 1);
                ps[ab[j][1] - 1].ad.Add(ab[j][0] - 1);
            }
            var set = new HashSet<int>();
            dfs(set, ps, 0);
            if (set.Count != nm[0]) res++;
        }
        WriteLine(res);
    }
    private static void dfs(HashSet<int> set,P[] ps,int index)
    {
        set.Add(index);
        foreach (var ad in ps[index].ad)
            if (!set.Contains(ad))
                dfs(set, ps, ad);
        
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}