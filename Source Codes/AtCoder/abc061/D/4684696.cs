using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;
//using static System.Globalization.CultureInfo;

class Program
{ 
    static void Main(string[] args)
    {
        var nm = Input.ar;
        var ps = P.Make(nm[0], nm[1], false);
        ps[0].Weight = 0;
        if (belf(ps))
            WriteLine(-ps[nm[0] - 1].Weight);
        else WriteLine("inf");
    }
    private static bool belf(P[] ps)
    {
        for (var i = 0; i < ps.Length - 1; i++)
            for (var j = 0; j < ps.Length; j++)
                foreach (var ad in ps[j].adj)
                    if (ps[j].Weight != Input.Inf && ps[ad].Weight > ps[j].Weight + ps[j].dist[ad])
                        ps[ad].Weight = ps[j].Weight + ps[j].dist[ad];
        var bo = new bool[ps.Length];
        for (var i = 0; i < ps.Length; i++)
            foreach (var ad in ps[i].adj)
            {
                if (ps[i].Weight == Input.Inf) continue;
                if (bo[i] || ps[ad].Weight > ps[i].Weight + ps[i].dist[ad])
                {
                    ps[ad].Weight = Min(ps[ad].Weight,ps[i].Weight + ps[i].dist[ad]);
                    bo[ad] = true;
                }
            }
        return !bo[ps.Length - 1]; 
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
    public static Tuple<int, int, long> MakeEdge(int num1, int num2, long weight)
        => new Tuple<int, int, long>(num1, num2, weight);
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
    public static P[] Make(int num, int edge, bool isNotDirected = true, bool isWeighted = true)
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
                if(isWeighted)
                ps[inp[j]].dist[inp[1 - j]] = -inp[2];
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