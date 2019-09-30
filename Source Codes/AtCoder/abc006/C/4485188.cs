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
        for(var i = 0; i <= nm[0]; i++)
        {
            var a = i + 3 * nm[0] - nm[1];
            var b = nm[1] - 2 * nm[0] - 2 * i;
            if (a >= 0 && b >= 0)
            {
                WriteLine($"{a} {b} {i}");
                return;
            }
        }
        WriteLine("-1 -1 -1");
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