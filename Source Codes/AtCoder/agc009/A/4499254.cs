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
        var num = Input.num;
        var ab = new long[num][];
        for (var i = 0; i < num; i++)
            ab[i] = Input.arL;
        var ct = 0L;
        ab = ab.Reverse().ToArray();
        for (var i = 0; i < num; i++)
            ct += (ab[i][1] - (ab[i][0] + ct) % ab[i][1])%ab[i][1];
        WriteLine(ct);
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