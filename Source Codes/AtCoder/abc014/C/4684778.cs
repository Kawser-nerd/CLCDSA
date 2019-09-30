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
        const int NUM = 1000002;
        var imos = new int[NUM];
        for(var i=0;i<num;i++)
        {
            var ab = Input.ar;
            imos[ab[0]]++;
            imos[ab[1] + 1]--;
        }
        for (var i = 1; i < NUM; i++)
            imos[i] += imos[i - 1];
        WriteLine(imos.Max());
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
    public static Tuple<int, int, long> MakeEdge(int num1, int num2, long weight)
        => new Tuple<int, int, long>(num1, num2, weight);
    public const long Inf = (long)1e18;
    public const double eps = 1e-11;
    public  const string Alfa = "abcdefghijklmnopqrstuvwxyz";
    public  const int MOD = 1000000007;
}