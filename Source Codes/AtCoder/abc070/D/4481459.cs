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
        for(var i = 0; i < num - 1; i++)
        {
            var inp = Input.ar;
            for(var j = 0; j < 2; j++)
            {
                ps[inp[j] - 1].ad.Add(inp[(j + 1) % 2] - 1);
                ps[inp[j] - 1].weights[inp[(j + 1) % 2] - 1] = inp[2];
            }
        }
        var qk = Input.ar;
        var union = new UnionFind<int>();
        for (var i = 0; i < num; i++)
            union.MakeSet(i);
        dfs(ps, union, qk[1] - 1, qk[1] - 1);
        var res = new long[qk[0]];
        for(var i = 0; i < qk[0]; i++)
        {
            var qer = Input.ar;
            res[i] = ps[qer[0] - 1].Weight + ps[qer[1] - 1].Weight;
        }
        WriteLine(string.Join("\n", res));
    }
    private static void dfs(P[] ps,UnionFind<int> union,int index,int s)
    {
        union.Union(index, s);
        foreach (var ad in ps[index].ad)
            if (!union.IsSame(index,ad))
            {
                ps[ad].Weight = ps[index].weights[ad] + ps[index].Weight;
                dfs(ps, union, ad, s);
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

public class UnionFind<T>
{
    private class Vertex
    {
        public T Key { get; set; }
        public Vertex Parent { get; set; }
        public int Rank { get; set; }
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
    private readonly Vertex NIL;

    public int Count { get; private set; }

    public UnionFind()
    {
        NIL = new Vertex(default(T));
        dics = new Dictionary<T, Vertex>();
    }
    
    public T parent(T key)
        => FindSet(dics[key].Parent).Key;
    
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
        dics[key] = new Vertex(key, NIL, 0);
        dics[key].Parent = dics[key];
        Count++;
        return true;
    }

    public bool Union(T key1, T key2)
    {
        if (!dics.ContainsKey(key1) || !dics.ContainsKey(key2))
            return false;
        if (IsSame(key1, key2)) return false;
        Link(FindSet(dics[key1]), FindSet(dics[key2]));
        Count--;
        return true;
    }

    private void Link(Vertex vex1, Vertex vex2)
    {
        if (vex1.Rank > vex2.Rank)
        {
            vex2.Parent = vex1;
        }
        else
        {
            vex1.Parent = vex2;
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