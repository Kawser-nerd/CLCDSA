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
        var hw = Input.ar;
        var cost = Enumerable.Repeat(0, 10).Select(v => Input.ar).ToArray();
        for (var k = 0; k < 10; k++)
            for (var j = 0; j < 10; j++)
                for (var i = 0; i < 10; i++)
                    cost[j][i] = Min(cost[j][i], cost[j][k] + cost[k][i]);
        WriteLine(Enumerable.Repeat(0, hw[0]).Sum(v => Input.ar.Sum(w => w == -1 ? 0 : cost[w][1])));
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