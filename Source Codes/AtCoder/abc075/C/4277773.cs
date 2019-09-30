using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    struct P
    {
        public int index;
        public List<int> ad;
        public P(int index)
        {
            this.index = index;
            ad = new List<int>();
        }
    }
    static void Main(string[] args)
    {
        var nm = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var ab = new int[nm[1]][];
        for (var i = 0; i < nm[1]; i++)
            ab[i] = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var res = 0;
        for(var i = 0; i < nm[1]; i++)
        {
            var ps = new P[nm[0]];
            for (var j = 0; j < nm[0]; j++)
                ps[j] = new P(j);
            for(var j = 0; j < nm[1]; j++)
            {
                if (i == j) continue;
                ps[ab[j][0] - 1].ad.Add(ab[j][1] - 1);
                ps[ab[j][1] - 1].ad.Add(ab[j][0] - 1);
            }
            var union = new UnionFind<int>();
            for (var j = 0; j < nm[0]; j++)
                union.MakeSet(j);
            dfs(ps, union, 0);
            if (union.Count != 1) res++;
        }
        WriteLine(res);
    }
    private static void dfs(P[] ps,UnionFind<int> union,int index)
    {
        foreach (var item in ps[index].ad)
        {
            if (!union.IsSame(item,index))
            {
                union.Union(index,item);
                dfs(ps, union,item);
            }
        }
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
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

    public bool IsSame(T key1, T key2)
    {
        if (!dics.ContainsKey(key1) || !dics.ContainsKey(key2))
            throw new ArgumentException("?????????????");
        return ReferenceEquals(FindSet(dics[key1]), FindSet(dics[key2]));
    }

    public bool MakeSet(T key)
    {
        if (dics.ContainsKey(key))
            throw new ArgumentException($"{key}??????????????????");
        dics[key] = new Vertex(key, NIL, 0);
        dics[key].Parent = dics[key];
        Count++;
        return true;
    }

    public bool Union(T key1, T key2)
    {
        if (!dics.ContainsKey(key1) || !dics.ContainsKey(key2))
            throw new ArgumentException("?????????????");
        if (key1.Equals(key2)) return false;
        Link(FindSet(dics[key1]), FindSet(dics[key2]));
        Count--;
        return true;
    }

    private bool Link(Vertex vex1, Vertex vex2)
    {
        if (vex1.Rank > vex2.Rank)
            vex2.Parent = vex1;
        else
        {
            vex1.Parent = vex2;
            if (vex1.Rank == vex2.Rank)
                vex2.Rank++;
        }
        return true;
    }

    private Vertex FindSet(Vertex vex)
    {
        if (!ReferenceEquals(vex.Parent, vex))
            vex.Parent = FindSet(vex.Parent);
        return vex.Parent;
    }
}