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
        var ab = Input.ar;
        var m = Input.num;
        var ads = new List<int>[num];
        for (var i = 0; i < num; i++)
            ads[i] = new List<int>();
        for(var i = 0; i < m; i++)
        {
            var inp = Input.ar;
            ads[inp[0] - 1].Add(inp[1] - 1);
            ads[inp[1] - 1].Add(inp[0] - 1);
        }
        var weights = new int[num];
        var queue = new Queue<int>();
        queue.Enqueue(ab[0] - 1);
        while (queue.Count != 0)
        {
            var p = queue.Dequeue();
            foreach (var ad in ads[p])
                if (ad != ab[0] - 1 && weights[ad] == 0)
                {
                    weights[ad] = weights[p] + 1;
                    queue.Enqueue(ad);
                }
        }
        var dagAd = new List<int>[num];
        for (var i = 0; i < num; i++)
            dagAd[i] = new List<int>();
        for (var i = 0; i < num; i++)
            for (var j = 0; j < num; j++)
                if (i != j && ads[i].Contains(j) && weights[i] - weights[j] == 1)
                    dagAd[i].Add(j);
        var res = new long[num];
        var Th = new bool[num];
        res[ab[0] - 1] = 1;
        Th[ab[0] - 1] = true;
        WriteLine(dp(dagAd, ab[1] - 1, res, Th));
    }
    private static long dp(List<int>[] ads,int index,long[] res,bool[] Th)
    {
        if (Th[index])
            return res[index];
        var sum = 0L;
        foreach (var ad in ads[index])
            sum += dp(ads, ad, res, Th);
        Th[index] = true;
        return res[index] = sum % Input.MOD;
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