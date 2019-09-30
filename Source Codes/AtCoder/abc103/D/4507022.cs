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
        var ab = new int[nm[1]][];
        for (var i = 0; i < nm[1]; i++)
            ab[i] = Input.ar;
        ab = ab.OrderBy(c => c[1]).ToArray();
        var ct = 0;
        var last = -1;
        for(var i = 0; i < nm[1]; i++)
        {
            if (last <= ab[i][0])
            {
                ct++;
                last = ab[i][1];
            }
        }
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