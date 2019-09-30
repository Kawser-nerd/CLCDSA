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
    static void Solve()
    {
        var num = Input.num;
        var xy = new int[num][];
        for(var i = 0; i < num; i++)
        {
            var inp = Input.ar;
            xy[i] = new[] { inp[0], inp[1], i };
        }
        var eg = new List<Edge>();
        var uf = UnionFind<int>.Make(num);
        for (var h = 0; h < 2; h++)
        {
            xy = xy.OrderBy(v => v[h]).ToArray();
            for (var i = 0; i < num - 1; i++)
                eg.Add(new Edge(xy[i][2], xy[i + 1][2], xy[i + 1][h] - xy[i][h]));
        }
        var ee = eg.OrderBy(v => v.Item3);
        var res = 0L;
        foreach (var e in ee)
            if(!uf.IsSame(e.Item1,e.Item2))
            {
                uf.Union(e.Item1, e.Item2);
                res += e.Item3;
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
    public static int[][] ar2D(int num)
        => Enumerable.Repeat(0, num).Select(v => ar).ToArray();
    public static long[][] arL2D(int num)
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
            inp[0]--;inp[1]--;
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