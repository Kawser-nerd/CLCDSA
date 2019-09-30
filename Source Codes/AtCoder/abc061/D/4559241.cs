using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;
//using static System.Globalization.CultureInfo;

class Program
{
    class P
    {
        public int index;
        public List<int> adj;
        public Dictionary<int, long> weights;
        public long Weight;
        public P(int index)
        {
            this.index = index;
            adj = new List<int>();
            weights = new Dictionary<int, long>();
            Weight = long.MaxValue;
        }
    }
    static void Main(string[] args)
    {
        var nm = Input.ar;
        var ps = Enumerable.Range(0, nm[0]).Select(v => new P(v)).ToArray();
        for(var i = 0; i < nm[1]; i++)
        {
            var inp = Input.ar;
            ps[inp[0] - 1].adj.Add(inp[1] - 1);
            ps[inp[0] - 1].weights[inp[1] - 1] = -inp[2];
        }
        var bo = new bool[nm[0]];
        ps[0].Weight = 0;
        for (var i = 0; i < nm[0]; i++)
            foreach (var p in ps)
                foreach (var ad in p.adj)
                    if(p.Weight!=long.MaxValue)
                    ps[ad].Weight = Min(ps[ad].Weight, p.Weight + p.weights[ad]);
        var ans = -ps[nm[0] - 1].Weight;
        foreach (var p in ps)
            foreach (var ad in p.adj)
            {
                if (p.Weight == long.MaxValue) continue;
                if (!bo[ad])
                    bo[ad] = bo[p.index];
                if (ps[ad].Weight > p.Weight + p.weights[ad])
                {
                    ps[ad].Weight = p.Weight + p.weights[ad];
                    bo[ad] = true;
                }
            }
        WriteLine(bo[nm[0] - 1] ? "inf" : ans.ToString());
    }
}

public class Input
{
    public static string read => ReadLine();
    public  static int[] ar => Array.ConvertAll(read.Split(' '), int.Parse);
    public  static int num => ToInt32(read);
    public  static long[] arL => Array.ConvertAll(read.Split(' '), long.Parse);
    public  static long numL => ToInt64(read);
    public  const string Alfa = "abcdefghijklmnopqrstuvwxyz";
    public  const int MOD = 1000000007;
}