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
        var num = Input.num;var min = int.MaxValue;
        for(var i = 1; i < num; i++)
        {
            var j = num - i;
            min = Min(min, Sum(i) + Sum(j));
        }
        WriteLine(min);
    }
    private static int Sum(int num)
    {
        var s = num.ToString();
        var res = 0;
        for (var i = 0; i < s.Length; i++)
            res += int.Parse(s.Substring(i,1));
        return res;
    }
}

public class Input
{
    public static string read => ReadLine();
    public  static int[] ar => Array.ConvertAll(read.Split(' '), int.Parse);
    public  static int num => ToInt32(read);
    public  
static long[] arL => Array.ConvertAll(read.Split(' '), long.Parse);
    public  static long numL => ToInt64(read);
    public static int[][] twodim(int num)
        => Enumerable.Repeat(0, num).Select(v => ar).ToArray();
    public static long[][] twodimL(int num)
        => Enumerable.Repeat(0, num).Select(v => arL).ToArray();
    public  const string Alfa = "abcdefghijklmnopqrstuvwxyz";
    public  const int MOD = 1000000007;
}