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
        var nm = Input.ar;
        var sum = 0;
        var imos = new int[nm[1] + 1];
        for(var i = 0; i < nm[0]; i++)
        {
            var lrs = Input.ar;
            sum += lrs[2];
            imos[lrs[0] - 1] += lrs[2];
            imos[lrs[1]] -= lrs[2];
        }
        for (var i = 1; i < nm[1]; i++)
            imos[i] += imos[i - 1];
        WriteLine(sum - imos.Take(nm[1]).Min());
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