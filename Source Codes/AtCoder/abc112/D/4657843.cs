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
        var pp = new List<int>();
        for (var i = 1; i * i <= nm[1]; i++)
            if (nm[1] % i == 0)
            {
                pp.Add(i);
                if (i != nm[1] / i)
                    pp.Add(nm[1] / i);
            }
        WriteLine(pp.Where(v => v <= nm[1] / nm[0]).Max());
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