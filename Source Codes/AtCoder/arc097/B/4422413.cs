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
        var nm = Add.ar;
        var ps = Add.ar;
        var un = new UnionFind<int>();
        for (var i = 0; i < nm[0]; i++)
            un.MakeSet(i + 1);
        for(var i = 0; i < nm[1]; i++)
        {
            var input = Add.ar;
            un.Union(input[0], input[1]);
        }
        var res = 0;
        for (var i = 0; i < nm[0]; i++)
            if (un.IsSame(i + 1, ps[i]))
                res++;
        WriteLine(res);
    }
}

public class Add
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
            throw new ArgumentException("?????????????");
        return ReferenceEquals(FindSet(dics[key1]),FindSet(dics[key2]));
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
        if (IsSame(key1, key2)) return false;
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