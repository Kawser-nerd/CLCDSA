using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    class P
    {
        public int index;
        public List<int> ads;

        public P(int index)
        {
            this.index = index;
            ads = new List<int>();
        }
    }
    static void Main(string[] args)
    {
        var nm = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var ab = new int[nm[1]][];
        for (var i = 0; i < nm[1]; i++)
        {
            var s = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
            ab[i] = new int[2];
            ab[i][0] = s[0];
            ab[i][1] = s[1];
        }
        var result = 0;
        for (var i = 0; i < nm[1]; i++)
        {
            var ps = new P[nm[0]];
            for (var j = 0; j < nm[0]; j++) ps[j] = new P(j);
            for (var j = 0; j < nm[1]; j++)
            {
                if (i == j) continue;
                ps[ab[j][0]-1].ads.Add(ab[j][1]-1);
                ps[ab[j][1]-1].ads.Add(ab[j][0]-1);
            }
            var s = new HashSet<int>();
            iscorr(ps, s, 0);
            if (s.Count != nm[0]) result++;
        }
        WriteLine(result);
    }

    private static void iscorr(P[] ps, HashSet<int> set,int index)
    {
        set.Add(index);
        foreach (var p in ps[index].ads)
        {
            if (!set.Contains(p)) iscorr(ps, set,p); 
        }
    }
}