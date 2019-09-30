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
        var num = Input.num;
        var adj = Enumerable.Repeat(0, num).Select(v => new List<int>()).ToArray();
        for(var i = 0; i < num-1; i++)
        {
            var inp = Input.ar;
            adj[inp[0] - 1].Add(inp[1] - 1);
            adj[inp[1] - 1].Add(inp[0] - 1);
        }
        var ct = new[] { 0, 0 };
        var th = new bool[num];
        th[0] = true;
        th[num - 1] = true;
        var que = new Queue<Pair>();
        que.Enqueue(new Pair(0, 0));
        que.Enqueue(new Pair(num-1, 1));
        while (que.Count != 0)
        {
            var p = que.Dequeue();
            ct[p.Item2]++;
            foreach (var ad in adj[p.Item1])
                if (!th[ad])
                {
                    th[ad] = true;
                    que.Enqueue(new Pair(ad, p.Item2));
                }
        }
        WriteLine(ct[0] > ct[1] ? "Fennec" : "Snuke");
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