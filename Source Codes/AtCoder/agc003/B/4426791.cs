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
        var ar = new int[num];
        for (var i = 0; i < num; i++)
            ar[i] = Add.num;
        var res = 0L;
        for(var i = 0; i < num; i++)
        {
            res += ar[i] / 2;
            ar[i] %= 2;
            if (i != num - 1)
            {
                var min = Min(ar[i], ar[i + 1]);
                ar[i] -= min;
                ar[i + 1] -= min;
                res += min;
            }
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