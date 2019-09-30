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
        var num = Add.num;
        var ar = Add.arL;
        Array.Sort(ar);
        var sum = new long[num + 1];
        for (var i = 1; i <= num; i++)
            sum[i] = sum[i - 1] + ar[i - 1];
        var res = num;
        for (var i = 1; i < num; i++)
        {
            if (2 * sum[i] < ar[i])
                res = num - i;
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