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
        var ar = Input.ar;
        var ct = new int[3];
        for (var i = 0; i < num; i++)
            if (ar[i] % 4 == 0) ct[2]++;
            else if (ar[i] % 2 == 0) ct[1]++;
            else ct[0]++;
        if (ct[2] >= ct[0]) WriteLine("Yes");
        else if (ct[2] == ct[0] - 1 && ct[1] == 0) WriteLine("Yes");
        else WriteLine("No");
    }
}

public class Input
{
    public static string read => ReadLine();
    public  static int[] ar => Array.ConvertAll(read.Split(' '), int.Parse);
    public  static int num => ToInt32(read);
    public static long[] arL => Array.ConvertAll(read.Split(' '), long.Parse);
    public  static long numL => ToInt64(read);
    public static int[][] twodim(int num)
        => Enumerable.Repeat(0, num).Select(v => ar).ToArray();
    public static long[][] twodimL(int num)
        => Enumerable.Repeat(0, num).Select(v => arL).ToArray();
    public const double eps = 1e-11;
    public  const string Alfa = "abcdefghijklmnopqrstuvwxyz";
    public  const int MOD = 1000000007;
}