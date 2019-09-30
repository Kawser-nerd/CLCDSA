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
        var rb = Input.arL;
        var xy = Input.ar;
        var left = 0L;
        var right = long.MaxValue;
        while (right > left + 1)
        {
            var mid = (right + left) / 2;
            var cc = rb[0] >= mid && rb[1] >= mid;
            var calc = (rb[0] - mid) / (xy[0] - 1) + (rb[1] - mid) / (xy[1] - 1);
            if (cc && calc >= mid)
                left = mid;
            else right = mid;
        }
        WriteLine(left);
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