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
        var nk = Input.ar;
        var ar = Enumerable.Repeat(0, nk[0]).Select(v => Input.num).ToArray();
        if (ar.Contains(0))
        {
            WriteLine(nk[0]);
            return;
        }
        var right = 1;
        var left = 0;
        long pro = ar[0];
        var max = ToInt32(ar[0] <= nk[1]);
        while (left < nk[0]&&right<nk[0])
        {
            if (pro * ar[right] <= nk[1])
            {
                max = Max(right - left + 1, max);
                pro *= ar[right];
                right++;
            }
            else if (right == left)
            {
                right++;
                left++;
            }
            else
            {
                pro = Max(1, pro / ar[left]);
                left++;
            }
        }
        WriteLine(max);
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