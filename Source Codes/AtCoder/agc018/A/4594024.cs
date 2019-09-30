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
        var nk = Input.ar;
        var ar = Input.ar;
        var gcd = ar[0];
        for (var i = 1; i < nk[0]; i++)
            gcd = Calculation.GCD(gcd, ar[i]);
        WriteLine(ar.Max() >= nk[1] && nk[1] % gcd == 0 ? "POSSIBLE" : "IMPOSSIBLE");
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

public class Calculation
{
    public static int LCM(int num1, int num2)
    {
        return num1 / GCD(num1, num2) * num2;
    }

    public static long LCM(long num1, long num2)
    {
        return num1 / GCD(num1, num2) * num2;
    }

    public static int GCD(int num1, int num2)
    {
        return num1 < num2 ? GCD(num2, num1) :
            num2 > 0 ? GCD(num2, num1 % num2) : num1;
    }

    public static long GCD(long num1, long num2)
    {
        return num1 < num2 ? GCD(num2, num1) :
            num2 > 0 ? GCD(num2, num1 % num2) : num1;
    }

    public static long[] Ncr(int num1)
    {
        if (num1 == 0) return new[] { 0L };
        var ncr = new long[num1 + 2];
        ncr[1] = 1;
        for(var i = 0; i < ncr.Length - 2; i++)
        {
            var tmp = new long[num1 + 2];
            tmp[num1 + 1] = 1;
            for (var j = 1; j <= ncr.Length - 2; j++)
                tmp[j] = (ncr[j] + ncr[j - 1]) % Input.MOD;
            ncr = tmp;
        }
        return ncr;
    }

    public static long Ncr(int num1, int num2)
        => Ncr(num1)[num2 + 1];
}