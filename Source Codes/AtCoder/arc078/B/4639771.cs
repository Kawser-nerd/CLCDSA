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
        var ps = P.Make(num, num - 1, isWeighted: false);
        var ar = new[] { 0, num - 1 };
        var wei = new long[2][];
        for(var i = 0; i < 2; i++)
        {
            var queue = new Queue<int>();
            for (var j = 0; j < num; j++)
                ps[j].Weight = 0;
            queue.Enqueue(ar[i]);
            var bo = new bool[num];bo[ar[i]] = true;
            while (queue.Count != 0)
            {
                var p = queue.Dequeue();
                foreach (var ad in ps[p].adj)
                    if (!bo[ad])
                    {
                        bo[ad] = true;
                        ps[ad].Weight = ps[p].Weight + 1;
                        queue.Enqueue(ad);
                    }
            }
            wei[i] = ps.Select(v => v.Weight).ToArray();
        }
        var fct = 0;
        var sct = 0;
        for (var i = 0; i < num; i++)
            if (wei[0][i] <= wei[1][i]) fct++;
            else sct++;
        WriteLine(fct <= sct ? "Snuke" : "Fennec");
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

public class P : IComparable<P>
{
    public int index;
    public List<int> adj;
    public Dictionary<int, int> dist;
    public long Weight;
    public P(int index)
    {
        this.index = index;
        adj = new List<int>();
        dist = new Dictionary<int, int>();
        Weight = long.MaxValue;
    }
    public static P[] Make(int num, int edge, bool isNotDirection = true, bool isWeighted = true)
    {
        var ps = Enumerable.Range(0, num).Select(v => new P(v)).ToArray();
        for (var i = 0; i < edge; i++)
        {
            var inp = Input.ar;
            inp[0]--;
            inp[1]--;
            for (var j = 0; j <= ToInt32(isNotDirection); j++)
            {
                ps[inp[j]].adj.Add(inp[1 - j]);
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