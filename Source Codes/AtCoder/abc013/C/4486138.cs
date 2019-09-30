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
        var nh = Input.arL;
        var atoe = Input.arL;
        var res = long.MaxValue;
        for(var i = 0; i <= nh[0]; i++)
        {
            var y = (long)Floor((double)(nh[0] * atoe[4] - (atoe[1] + atoe[4]) * i - nh[1]) / (atoe[4] + atoe[3])) + 1;
            res = Min(res, i * atoe[0] + Max(y, 0) * atoe[2]);
        }
        WriteLine(res == long.MaxValue ? 0 : res);
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