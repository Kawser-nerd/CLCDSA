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
        var adj = Enumerable.Repeat(0, num).Select(_ => new List<int>()).ToArray();
        for(var i = 0; i < num - 1; i++)
        {
            var inp = Input.ar;
            adj[inp[0] - 1].Add(inp[1] - 1);
            adj[inp[1] - 1].Add(inp[0] - 1);
        }
        var st = new int[num];
        st[0] = 1;
        st[num - 1] = 2;
        var qu = new Queue<int>();
        qu.Enqueue(0);
        qu.Enqueue(num - 1);
        while (qu.Count != 0)
        {
            var p = qu.Dequeue();
            foreach (var ad in adj[p])
                if (st[ad] == 0)
                {
                    st[ad] = st[p];
                    qu.Enqueue(ad);
                }
        }
        WriteLine(st.Count(b => b == 1) > st.Count(b => b == 2) ? "Fennec" : "Snuke");
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