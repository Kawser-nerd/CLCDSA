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
        var num = Input.numL;
        var depth = (int)Floor(Log(num, 2)) % 2;
        var ct = -1;
        var lo = 1L;
        while (lo <= num)
        {
            ct++;
            if ((depth + ct) % 2 == 1)
                lo *= 2;
            else lo = 2 * lo + 1;
        }
        WriteLine(ct % 2 == 0 ? "Aoki" : "Takahashi");
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