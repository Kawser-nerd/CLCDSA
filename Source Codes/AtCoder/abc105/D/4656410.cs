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
        var ar = Input.ar;
        var dic = new Dictionary<long, int>();
        var sum = new long[nm[0] + 1];
        for (var i = 0; i < nm[0]; i++)
            sum[i + 1] += sum[i] + ar[i];
        for (var i = 0; i <= nm[0]; i++)
            if (dic.ContainsKey(sum[i] % nm[1]))
                dic[sum[i] % nm[1]]++;
            else dic[sum[i] % nm[1]] = 1;
        var res = 0L;
        foreach (var val in dic.Values)
            res += (long)val * (val - 1) / 2;
        WriteLine(res);
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