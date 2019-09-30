using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;
using Pair = System.Tuple<int, int>;
using Edge = System.Tuple<int, int, long>;
//using static System.Globalization.CultureInfo;
 
class Program
{
    static void Main(string[] args)
    {
        var nm = Input.ar;
        var ps = P.Make(nm[0], nm[1], isWeighted: false);
        var ct = 0;
        var th = new bool[nm[0]];
        for (var i = 0; i < nm[0]; i++)
            if (!th[i] && dfs(ps, i,-1, th)) ct++;
        WriteLine(ct);
    }
    private static bool dfs(P[] ps,int index,int then,bool[] th)
    {
        th[index] = true;
        var b = true;
        foreach (var ad in ps[index].adj)
            if (ad == then) continue;
            else if (th[ad])
                return false;
            else b &= dfs(ps, ad, index, th);
        return b;
    }
}
 
public class Input
{
    public static string read => ReadLine();
    public  static int[] ar => Array.ConvertAll(read.Split(' '), int.Parse);
    public  static int num => ToInt32(read);
    public static long[] arL => Array.ConvertAll(read.Split(' '), long.Parse);
    public  static long numL => ToInt64(read);
    public static string[] gred(int h) 
        => Enumerable.Repeat(0, h).Select(v => read).ToArray();
    public static int[][] twodim(int num)
        => Enumerable.Repeat(0, num).Select(v => ar).ToArray();
    public static long[][] twodimL(int num)
        => Enumerable.Repeat(0, num).Select(v => arL).ToArray();
    public const long Inf = (long)1e18;
    public const double eps = 1e-11;
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
    public P(int index):this(index,(long)1e18)
    {
    }
    public P(int index,long Weight)
    {
        this.index = index;
        adj = new List<int>();
        rev = new List<int>();
        dist = new Dictionary<int, int>();
        this.Weight = Weight;
    }
    public static P[] Make(int num)
        => Enumerable.Range(0, num).Select(v => new P(v)).ToArray();
    public static P[] Make(int num, int edge, bool isNotDirected = true, bool isWeighted = true)
    {
        var ps = Make(num);
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
                if(isWeighted)
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