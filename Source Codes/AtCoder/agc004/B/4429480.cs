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
        var nx = Add.arL;
        var ar = Add.arL;
        var res = long.MaxValue;
        var min = Enumerable.Repeat(long.MaxValue,(int)nx[0]).ToArray();
        for(var k = 0; k < nx[0]; k++)
        {
            for(var i = 0; i < nx[0]; i++)
            {
                long index;
                if (i - k >= 0)
                    index = i - k;
                else
                    index = nx[0] + (i - k);
                min[i] = Min(min[i], ar[index]);
            }
            res = Min(res, min.Sum() + k * nx[1]);
        }
        WriteLine(res);
    }
}

public class Add
{
    public static string read => ReadLine();
    public  static int[] ar => Array.ConvertAll(read.Split(' '), int.Parse);
    public  static int num => ToInt32(read);
    public  static long[] arL => Array.ConvertAll(read.Split(' '), long.Parse);
    public  static long numL => ToInt64(read);
    public  const string Alfa = "abcdefghijklmnopqrstuvwxyz";
    public  const int MOD = 1000000007;
}