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
        var xyr = Input.ar;
        var xy = Input.ar;
        if (xyr[0] - xy[0] >= xyr[2] && xy[2] - xyr[0] >= xyr[2] && xyr[1] - xy[1] >= xyr[2] && xy[3] - xyr[1] >= xyr[2])
        {
            WriteLine("NO\nYES");
            return;
        }
        var ar1 = new[] { Pow(xyr[0] - xy[2], 2), Pow(xyr[0] - xy[0], 2) };
        var ar2 = new[] { Pow(xyr[1] - xy[1], 2), Pow(xyr[1] - xy[3], 2) };
        var list = new List<double>();
        for (var i = 0; i < 2; i++)
            for (var j = 0; j < 2; j++)
                list.Add(ar1[i] + ar2[j]);
        if (list.Select(v=>v>xyr[2]*xyr[2]).Count(b=>b)==0)
        {
            WriteLine("YES\nNO");
            return;
        }
        WriteLine("YES\nYES");
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