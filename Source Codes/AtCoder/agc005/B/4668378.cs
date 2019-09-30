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
        var num = Input.num;
        var ar = Input.ar;
        var index = new int[num + 1];
        for (var i = 0; i < num; i++)
            index[ar[i]] = i;
        var leftuf = new UnionFind<int>();
        var rightuf = new UnionFind<int>();
        for(var i = 0; i < num; i++)
        {
            leftuf.MakeSet(i);
            rightuf.MakeSet(i);
        }
        var res = 0L;
        for(var i = num; i > 0; i--)
        {
            var ind = index[i];
            var isr = ind != num - 1 && i < ar[ind + 1];
            var isl = ind != 0 && i < ar[ind - 1];
            if (isr)
                rightuf.Union(ind, ind + 1);
            if (isl)
                leftuf.Union(ind, ind - 1);
            res += (long)i * rightuf.Size(ind) * leftuf.Size(ind);
            if (isr)
                leftuf.Union(ind, ind + 1);
            if (isl)
                rightuf.Union(ind, ind - 1);
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
    public static int[][] twodim(int num)
        => Enumerable.Repeat(0, num).Select(v => ar).ToArray();
    public static long[][] twodimL(int num)
        => Enumerable.Repeat(0, num).Select(v => arL).ToArray();
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
    private readonly Vertex NIL;

    public int Count { get; private set; }

    public UnionFind()
    {
        NIL = new Vertex(default(T));
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
        dics[key] = new Vertex(key, NIL, 0);
        dics[key].Parent = dics[key];
        dics[key].Size = 1;
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

    public static UnionFind<int> Make(int[] nm)
    {
        var uf = new UnionFind<int>();
        for (var i = 0; i < nm[0]; i++)
            uf.MakeSet(i + 1);
        for(var i = 0; i < nm[1]; i++)
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