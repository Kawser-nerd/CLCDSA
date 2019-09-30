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
        var nm = Input.ar;
        var edge = new List<Edge>();
        for(var i=0;i<nm[0];i++)
        {
            var cost = Input.num;
            edge.Add(new Edge(i, nm[0], cost));
        }
        for (var i = 0; i < nm[1]; i++)
        {
            var e = Input.ar;
            edge.Add(new Edge(e[0] - 1, e[1] - 1, e[2]));
        }
        edge = edge.OrderBy(v => v.Item3).ToList();
        var uf = UnionFind<int>.Make(nm[0] + 1);
        var res = 0L;
        foreach (var eg in edge)
            if (!uf.IsSame(eg.Item1, eg.Item2))
            {
                uf.Union(eg.Item1, eg.Item2);
                res += eg.Item3;
            }
        WriteLine(res);
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
    public const long Inf = (long)1e18;
    public const double eps = 1e-6;
    public  const string Alfa = "abcdefghijklmnopqrstuvwxyz";
    public  const int MOD = 1000000007;
}

public class UnionFind<T>
{
    private class Vertex
    {
        public T Key { get; set; }
        public Vertex Parent { get; set; }
        public int Rank { get; set; }
        public int Size { get; set; }
        public Vertex(T key) : this(key, null, 0)
        {

        }
        public Vertex(T key, Vertex Parent, int rank)
        {
            this.Key = key;
            this.Parent = Parent;
            this.Rank = rank;
        }
    }
    private readonly Dictionary<T, Vertex> dics;

    public UnionFind()
    {
        dics = new Dictionary<T, Vertex>();
    }
    
    public T Parent(T key)
        => FindSet(dics[key].Parent).Key;
    public int Size(T key)
        => FindSet(dics[key].Parent).Size;

    public bool IsSame(T key1, T key2)
    {
        if (!dics.ContainsKey(key1) || !dics.ContainsKey(key2))
            return false;
        return ReferenceEquals(FindSet(dics[key1]),FindSet(dics[key2]));
    }

    public bool MakeSet(T key)
    {
        if (dics.ContainsKey(key))
            return false;
        dics[key] = new Vertex(key);
        dics[key].Parent = dics[key];
        dics[key].Size = 1;
        return true;
    }

    public bool Union(T key1, T key2)
    {
        if (!dics.ContainsKey(key1) || !dics.ContainsKey(key2))
            return false;
        if (IsSame(key1, key2)) return false;
        Link(FindSet(dics[key1]), FindSet(dics[key2]));
        return true;
    }

    public static UnionFind<int> Make(int num, int eg = 0)
    {
        var uf = new UnionFind<int>();
        for (var i = 0; i < num; i++)
            uf.MakeSet(i);
        for (var i = 0; i < eg; i++)
        {
            var inp = Input.ar;
            uf.Union(inp[0], inp[1]);
        }
        return uf;
    }

    private void Link(Vertex vex1, Vertex vex2)
    {
        if (vex1.Rank > vex2.Rank)
        {
            vex2.Parent = vex1;
            vex1.Size += vex2.Size;
        }
        else
        {
            vex1.Parent = vex2;
            vex2.Size += vex1.Size;
            if (vex1.Rank == vex2.Rank)
                vex2.Rank++;
        }
    }

    private Vertex FindSet(Vertex vex)
    {
        if (!ReferenceEquals(vex.Parent, vex))
            vex.Parent = FindSet(vex.Parent);
        return vex.Parent;
    }
}