using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;
using Pair = System.Tuple<int, int>;
using Edge = System.Tuple<int, int, long>;
//using Debug;
//using static System.Globalization.CultureInfo;

class Program
{
    static void Main(string[] args)
    {
        Solve();
        //WriteLine(Solve());
    }
    static int res;
    static bool[] th;
    static P[] ps;
    static void Solve()
    {
        var nm = Input.ar;
        ps = P.Make(nm[0], nm[1], isWeighted: false);
        th = new bool[nm[0]];
        dfs(0);
        WriteLine(res);
    }
    static void dfs(int index)
    {
        th[index] = true;
        if (th.All(b => b))
        {
            res++;
            th[index] = false;
            return;
        }
        foreach (var ad in ps[index].adj)
            if (!th[ad])
                dfs(ad);
        th[index] = false;
    }
}

public class Input
{
    public static string read => ReadLine();
    public  static int[] ar => Array.ConvertAll(read.Split(' '), int.Parse);
    public  static int num => ToInt32(read);
    public static long[] arL => Array.ConvertAll(read.Split(' '), long.Parse);
    public  static long numL => ToInt64(read);
    public static char[][] gred(int h) 
        => Enumerable.Repeat(0, h).Select(v => read.ToCharArray()).ToArray();
    public static int[][] ar2D(int num)
        => Enumerable.Repeat(0, num).Select(v => ar).ToArray();
    public static long[][] arL2D(int num)
        => Enumerable.Repeat(0, num).Select(v => arL).ToArray();
    public const long Inf = (long)1e18;
    public const double eps = 1e-6;
    public  const string Alfa = "abcdefghijklmnopqrstuvwxyz";
    public  const int MOD = 1000000007;
}

public class P : IComparable<P>
{
    public int index;
    public List<int> adj;
    public List<int> rev;
    public Dictionary<int, int> dist;
    public int parent;
    public long Weight { get; set; }
    public P(int index,long Weight=Input.Inf)
    {
        this.index = index;
        adj = new List<int>();
        rev = new List<int>();
        dist = new Dictionary<int, int>();
        this.Weight = Weight;
    }
    public static P[] Make(int num, int edge = 0, bool isNotDirected = true, bool isWeighted = true)
    {
        var ps = Enumerable.Range(0, num).Select(v => new P(v)).ToArray();
        for (var i = 0; i < edge; i++)
        {
            var inp = Input.ar;
            inp[0]--;
            inp[1]--;
            for (var j = 0; j <= ToInt32(isNotDirected); j++)
            {
                ps[inp[j]].adj.Add(inp[1 - j]);
                if (!isNotDirected)
                    ps[inp[1 - j]].rev.Add(inp[j]);
                if (isWeighted)
                    ps[inp[j]].dist[inp[1 - j]] = inp[2];
            }
        }
        return ps;
    }
    public override string ToString()
        => $"{index + 1} {Weight}";
    public override int GetHashCode()
        => index.GetHashCode();
    public int CompareTo(P p)
        => Weight.CompareTo(p.Weight);
}