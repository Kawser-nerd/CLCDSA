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
        public int Weight;
        public P(int index)
        {
            this.index = index;
            adj = new List<int>();
        }
    }
    static void Main(string[] args)
    {
        var num = Input.num;
        var ab = Input.ar;
        var m = Input.num;
        var ps = Enumerable.Range(0, num).Select(v => new P(v)).ToArray();
        for(var i = 0; i < m; i++)
        {
            var inp = Input.ar;
            ps[inp[0] - 1].adj.Add(inp[1] - 1);
            ps[inp[1] - 1].adj.Add(inp[0] - 1);
        }
        var queue = new Queue<P>();
        queue.Enqueue(ps[ab[0] - 1]);
        while (queue.Count != 0)
        {
            var p = queue.Dequeue();
            foreach (var ad in p.adj)
                if (ad != ab[0] - 1 && ps[ad].Weight == 0)
                {
                    ps[ad].Weight = p.Weight + 1;
                    queue.Enqueue(ps[ad]);
                }
        }
        WriteLine(dfs(ps, ab[1] - 1, ab[0] - 1, new long[num]));
    }
    private static long dfs(P[] ps,int index,int a,long[] memo)
    {
        if (index == a) return memo[index] = 1;
        if (memo[index] != 0) return memo[index];
        var sum = 0L;
        foreach (var ad in ps[index].adj)
            if (ps[ad].Weight + 1 == ps[index].Weight)
                sum += dfs(ps, ad, a,memo);
        return memo[index] = sum%Input.MOD;
    }
}

public class Input
{
    public static string read => ReadLine();
    public  static int[] ar => Array.ConvertAll(read.Split(' '), int.Parse);
    public  static int num => ToInt32(read);
    public static long[] arL => Array.ConvertAll(read.Split(' '), long.Parse);
    public  static long numL => ToInt64(read);
    public static int[][] twodim(int num)
        => Enumerable.Repeat(0, num).Select(v => ar).ToArray();
    public static long[][] twodimL(int num)
        => Enumerable.Repeat(0, num).Select(v => arL).ToArray();
    public  const string Alfa = "abcdefghijklmnopqrstuvwxyz";
    public  const int MOD = 1000000007;
}