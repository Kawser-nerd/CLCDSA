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
        var nk = Add.ar;
        var ar = Add.ar;
        var sum1 = new long[nk[0]+1];
        var sum2 = new long[nk[0]+1];
        sum1[0] = 0;
        sum2[0] = 0;
        for(var i = 1; i <= nk[0]; i++)
        {
            sum1[i] = sum1[i - 1] + ar[i-1];
            sum2[i] = sum2[i - 1] + Max(ar[i-1], 0);
        }
        var res = 0L;
        for(var i = 0; i < nk[0]-nk[1]+1; i++)
        {
            var bl = sum2[nk[0]] - (sum2[i + nk[1]] - sum2[i]);
            res = Max(res, bl);
            res = Max(res, bl + sum1[i + nk[1]] - sum1[i]);
        }
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