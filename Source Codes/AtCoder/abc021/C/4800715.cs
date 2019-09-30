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
    private static long[] memo;
    private static int[,] dist;
    private static bool[] th;
    static void Main(string[] args)
    {
        var num = Input.num;
        var ab = Input.ar;
        var m = Input.num;
        var ps = P.Make(num, m, isWeighted: false);
        dist = new int[num, num];
        memo = new long[num];
        th = new bool[num];
        for (var i = 0; i < num; i++)
            for (var j = 0; j < num; j++)
                if (ps[i].adj.Contains(j))
                    dist[i, j] = 1;
                else if (i != j) dist[i, j] = 105;
        for (var k = 0; k < num; k++)
            for (var i = 0; i < num; i++)
                for (var j = 0; j < num; j++)
                    dist[i, j] = Min(dist[i, j], dist[i, k] + dist[k, j]);
        WriteLine(dfs(ps, ab[1] - 1, ab[0] - 1));
    }
    static long dfs(P[] ps,int index,int a)
    {
        if (th[index]) return memo[index];
        if (index == a) return 1;
        th[index] = true;
        var sum = 0L;
        foreach (var ad in ps[index].adj)
            if (dist[a, index] == dist[a, ad] + 1)
                sum = (sum + dfs(ps, ad, a)) % Input.MOD;
        return memo[index] = sum;
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
    public static int[][] twodim(int num)
        => Enumerable.Repeat(0, num).Select(v => ar).ToArray();
    public static long[][] twodimL(int num)
        => Enumerable.Repeat(0, num).Select(v => arL).ToArray();
    public const long Inf = (long)1e18/2;
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
    public P parent;
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