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
        var ps = new P[nm[0]];
        var set = new HashSet<int>();
        for(var i = 0; i < nm[1]; i++)
        {
            var ab = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
            for(var j = 0; j <2; j++)
            {
                if (set.Contains(ab[j]))
                    ps[ab[j]-1].ad.Add(ab[1 - j]-1);
                else
                {
                    set.Add(ab[j]);
                    ps[ab[j]-1] = new P(ab[j]-1);
                    ps[ab[j]-1].ad.Add(ab[1 - j]-1);
                }
            }
        }
        set.Clear();
        var result = 0;
        get(ps, ref result, set,0);
        WriteLine(result);
    }

    private static void get(P[] ps,ref int result,HashSet<int> set,int i)
    {
        set.Add(i);
        for(var j = 0; j < ps[i].ad.Count; j++)
        {
            if (!set.Contains(ps[i].ad[j]))
                get(ps, ref result, set, ps[i].ad[j]);
        }
        if (set.Count == ps.Length) result++;
        set.Remove(i);
    }
}