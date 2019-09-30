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
        var ar = Enumerable.Repeat(0, num).Select(v => Input.num).ToArray();
        var res = 0L;
        for (var i = 0; i < num - 1; i++)
        {
            res += ar[i] / 2;
            ar[i] %= 2;
            if (ar[i] == 1 && ar[i + 1] != 0)
            {
                res++;
                ar[i + 1]--;
            }
        }
        WriteLine(res + ar[num - 1] / 2);
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