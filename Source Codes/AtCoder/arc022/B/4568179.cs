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
        var max = ar.Max();
        var bo = new bool[max];
        var right = 1;
        var left = 0;
        bo[ar[0] - 1] = true;
        var res = 1;
        var len = 1;
        while (right < num && left < num)
        {
            if (!bo[ar[right] - 1])
            {
                bo[ar[right] - 1] = true;
                len++;
                right++;
                res = Max(res, len);
            }
            else
            {
                bo[ar[left] - 1] = false;
                if(right==left)
                right++;
                left++;
                len = Max(0, len - 1);
            }
        }
        WriteLine(res);
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