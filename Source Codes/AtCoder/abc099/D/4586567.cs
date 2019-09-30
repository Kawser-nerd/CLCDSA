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
        var nc = Input.ar;
        var ds = Enumerable.Repeat(0, nc[1]).Select(v => Input.ar).ToArray();
        var color = Enumerable.Repeat(0, nc[0]).Select(v => Input.ar).ToArray();
        var ct = new int[3, nc[1] + 1];
        for(var i=0;i<nc[0];i++)
            for(var j = 0; j < nc[0]; j++)
            {
                var mod = (i + j) % 3;
                ct[mod, color[i][j]]++;
            }
        var res = int.MaxValue;
        for (var i=0;i<nc[1];i++)
            for(var j=0;j<nc[1];j++)
                for(var h = 0; h < nc[1]; h++)
                {
                    if (i == j || j == h || i == h) continue;
                    var ar = new[] { i, j, h };
                    var sum = 0;
                    for (var k = 0; k < 3; k++)
                        for (var c = 1; c <= nc[1]; c++)
                            sum += ct[k, c] * ds[c - 1][ar[k]];
                    res = Min(res, sum);
                }
        WriteLine(res);
    }
}

public class Input
{
    public static string read => ReadLine();
    public  static int[] ar => Array.ConvertAll(read.Split(' '), int.Parse);
    public  static int num => ToInt32(read);
    public  
static long[] arL => Array.ConvertAll(read.Split(' '), long.Parse);
    public  static long numL => ToInt64(read);
    public static int[][] twodim(int num)
        => Enumerable.Repeat(0, num).Select(v => ar).ToArray();
    public static long[][] twodimL(int num)
        => Enumerable.Repeat(0, num).Select(v => arL).ToArray();
    public  const string Alfa = "abcdefghijklmnopqrstuvwxyz";
    public  const int MOD = 1000000007;
}