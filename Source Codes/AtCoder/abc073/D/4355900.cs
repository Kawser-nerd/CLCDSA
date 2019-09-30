using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    class P
    {
        public int index;
        public List<int> ad;
        public Dictionary<int, int> weights;
        public int Weight;
        public P(int index)
        {
            this.index = index;
            ad = new List<int>();
            weights = new Dictionary<int, int>();
        }
    }
    static void Main(string[] args)
    {
        var nmr = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var r = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var ps = new P[nmr[0]];
        for (var i = 0; i < nmr[0]; i++)
            ps[i] = new P(i);
        for(var i = 0; i < nmr[1]; i++)
        {
            var input = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
            for(var j = 0; j < 2; j++)
            {
                ps[input[j] - 1].ad.Add(input[(j + 1) % 2] - 1);
                ps[input[j] - 1].weights[input[(j + 1) % 2] - 1] = input[2];
            }
        }
        var fromto = new int[nmr[0], nmr[0]];
        for(var i = 0; i < nmr[0]; i++)
        {
            Init(ps, i);
            var set = new HashSet<int>();
            while (true)
            {
                var minVal = int.MaxValue;
                var u = new P(-1);
                for(var j = 0; j < nmr[0]; j++)
                {
                    if (!set.Contains(j) && minVal > ps[j].Weight)
                    {
                        minVal = ps[j].Weight;
                        u = ps[j];
                    }
                }

                if (minVal == int.MaxValue) break;
                set.Add(u.index);

                foreach (var ad in u.ad)
                {
                    if (!set.Contains(ad) && ps[ad].Weight > u.Weight + u.weights[ad])
                    {
                        ps[ad].Weight = u.Weight + u.weights[ad];
                    }
                }
            }
            for (var j = 0; j < nmr[0]; j++)
                fromto[i, j] = ps[j].Weight;
        }
        var min = int.MaxValue;
        for (var i = 0; i < r.Length; i++)
            min = Min(min, dfs(fromto, r, new HashSet<int>(), i));
        WriteLine(min);
    }
    private static int dfs(int[,] fromto,int[] rs,HashSet<int> set,int index)
    {
        set.Add(rs[index]);
        if (set.Count == rs.Length)
        {
            set.Remove(rs[index]);
            return 0;
        }
        var min = int.MaxValue;
        for(var i = 0; i < rs.Length; i++)
        {
            if (!set.Contains(rs[i]))
                min = Min(min, dfs(fromto, rs, set, i)+fromto[rs[index]-1,rs[i]-1]);
        }
        set.Remove(rs[index]);
        return min;
    }
    private static void Init(P[] ps,int index)
    {
        for (var i = 0; i < ps.Length; i++)
            ps[i].Weight = int.MaxValue;
        ps[index].Weight = 0;
    }
}