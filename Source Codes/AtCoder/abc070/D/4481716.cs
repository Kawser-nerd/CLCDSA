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
        public Dictionary<int, int> weights;
        public long Weight;
        public P(int index)
        {
            this.index = index;
            ad = new List<int>();
            weights = new Dictionary<int, int>();
            Weight = 0;
        }
    }
    static void Main(string[] args)
    {

        var num = Input.num;
        var ps = new P[num];
        for (var i = 0; i < num; i++)
            ps[i] = new P(i);
        for (var i = 0; i < num - 1; i++)
        {
            var inp = Input.ar;
            for (var j = 0; j < 2; j++)
            {
                ps[inp[j] - 1].ad.Add(inp[(j + 1) % 2] - 1);
                ps[inp[j] - 1].weights[inp[(j + 1) % 2] - 1] = inp[2];
            }
        }
        var qk = Input.ar;
        dfs(ps, new bool[num], qk[1] - 1);
        var res = new long[qk[0]];
        for (var i = 0; i < qk[0]; i++)
        {
            var qer = Input.ar;
            res[i] = ps[qer[0] - 1].Weight + ps[qer[1] - 1].Weight;
        }
        WriteLine(string.Join("\n", res));
    }
    private static void dfs(P[] ps, bool[] set, int index)
    {
        set[index] = true;
        foreach (var ad in ps[index].ad)
            if (!set[ad])
            {
                ps[ad].Weight = ps[index].weights[ad] + ps[index].Weight;
                dfs(ps, set, ad);
            }
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