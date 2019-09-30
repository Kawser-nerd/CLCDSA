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
        var hwd = Input.ar;
        var ar = Enumerable.Repeat(0, hwd[0]).Select(v => Input.ar).ToArray();
        var pair = new KeyValuePair<int, int>[hwd[0] * hwd[1] + 1];
        for (var i = 0; i < hwd[0]; i++)
            for (var j = 0; j < hwd[1]; j++)
                pair[ar[i][j]] = new KeyValuePair<int, int>(i, j);
        var sum = new long[hwd[0] * hwd[1] + 1];
        for(var i = hwd[2]+1; i <= hwd[0] * hwd[1]; i++)
            sum[i] = sum[i - hwd[2]] + Abs(pair[i].Key - pair[i - hwd[2]].Key) + Abs(pair[i].Value - pair[i - hwd[2]].Value);
        var qur = Input.num;
        var res = new long[qur];
        for(var i = 0; i < qur; i++)
        {
            var lr = Input.ar;
            res[i] = sum[lr[1]] - sum[lr[0]];
        }
        WriteLine(string.Join("\n", res));
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