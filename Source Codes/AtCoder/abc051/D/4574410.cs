using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;
//using static System.Globalization.CultureInfo;

class Program
{
    class P
    {
        public int index;
        public List<int> adj;
        public Dictionary<int, long> weights;
        public P(int index)
        {
            this.index = index;
            adj = new List<int>();
            weights = new Dictionary<int, long>();
        }
    }
    static void Main(string[] args)
    {
        var nm = Input.ar;
        var ps = Enumerable.Range(0, nm[0]).Select(v => new P(v)).ToArray();
        var dist = new long[nm[0], nm[0]];
        for (var i = 0; i < nm[1]; i++)
        {
            var inp = Input.ar;
            for (var j = 0; j < 2; j++)
            {
                dist[inp[j] - 1, inp[1 - j] - 1] = inp[2];
                ps[inp[j] - 1].adj.Add(inp[1 - j] - 1);
                ps[inp[j] - 1].weights[inp[1 - j] - 1] = inp[2];
            }
        }
        for (var i = 0; i < nm[0]; i++)
            for (var j = 0; j < nm[0]; j++)
                if (i != j && dist[i, j] == 0)
                    dist[i,j] = int.MaxValue;
        for (var k = 0; k < nm[0]; k++)
            for (var i = 0; i < nm[0]; i++)
                for (var j = 0; j < nm[0]; j++)
                    dist[i, j] = Min(dist[i, j], dist[i, k] + dist[k, j]);
        var eg = Enumerable.Repeat(0, nm[0]).Select(v => new bool[nm[0]]).ToArray();
        dfs(ps, dist, new bool[nm[0]], eg, 0);
        WriteLine(eg.Sum(ar => ar.Count(b => b)));
       
    }
    private static void dfs(P[] ps,long[,] dist,bool[] bo,bool[][] edge,int index)
    {
        bo[index] = true;
        foreach (var ad in ps[index].adj)
        {
            if (!bo[ad])
                dfs(ps, dist, bo,edge,ad);
            var min = Min(ad, index);
            var max = Max(ad, index);
            if (!edge[min][max] && dist[index, ad] != ps[index].weights[ad])
                edge[min][max] = true;
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