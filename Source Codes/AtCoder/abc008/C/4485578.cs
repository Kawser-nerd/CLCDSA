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
        var coin = new int[num];
        for (var i = 0; i < num; i++)
            coin[i] = Input.num;
        Array.Sort(coin);
        var ct = new int[num];
        for (var i = 0; i < num; i++)
            for (var j = 0; j < num; j++)
                if (i != j && coin[j] % coin[i] == 0)
                    ct[j]++;
        var sum = 0d;
        for(var i = 0; i < num; i++)
        {
            sum += ct[i] % 2 == 1 ? 0.5 : (double)(ct[i] + 2) / (2 * ct[i] + 2);
        }
        WriteLine(sum);
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