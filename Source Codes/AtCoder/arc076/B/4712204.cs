using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;
//using static System.Globalization.CultureInfo;

class Program
{
    class G
    {
        public int index;
        public int x;
        public int y;
        public G(int index, int x,int y)
        {
            this.index = index;
            this.x = x;
            this.y = y;
        }
    }
    static void Main(string[] args)
    {
        var num = Input.num;
        var gs = new G[num];
        for(var i = 0; i < num; i++)
        {
            var xy= Input.ar;
            gs[i] = new G(i, xy[0], xy[1]);
        }
        gs = gs.OrderBy(g => g.x).ToArray();
        var edge = new List<Tuple<int, int, long>>();
        for (var i = 1; i < num; i++)
            edge.Add(new Tuple<int, int, long>(gs[i - 1].index, gs[i].index, Min(Abs(gs[i - 1].x - gs[i].x), Abs(gs[i - 1].y - gs[i].y))));
        gs = gs.OrderBy(g => g.y).ToArray();
        for (var i = 1; i < num; i++)
            edge.Add(new Tuple<int, int, long>(gs[i - 1].index, gs[i].index, Min(Abs(gs[i - 1].x - gs[i].x), Abs(gs[i - 1].y - gs[i].y))));
        edge = edge.OrderBy(v => v.Item3).ToList();
        var uf = new UnionFind<int>();
        for (var i = 0; i < num; i++)
            uf.MakeSet(i);
        var res = 0L;
        foreach (var ed in edge)
            if (!uf.IsSame(ed.Item1, ed.Item2))
            {
                uf.Union(ed.Item2, ed.Item1);
                res += ed.Item3;
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
            uf.MakeSet(i + 1);
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