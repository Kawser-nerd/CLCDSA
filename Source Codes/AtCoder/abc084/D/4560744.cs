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
        var qur = Input.num;
        const int NUM = (int)1e5 + 1;
        var bo = new bool[NUM];
        for (var i = 2; i < NUM; i++)
            if (!bo[i])
                for (var j = 2 * i; j < NUM; j += i)
                    bo[j] = true;
        var ct = new int[NUM];
        for (var i = 3; i < NUM; i += 2)
            ct[i] = ct[i - 2] + ToInt32(!bo[i] && !bo[(i + 1) / 2]);
        var res = new int[qur];
        for(var i = 0; i < qur; i++)
        {
            var lr = Input.ar;
            res[i] = lr[0] != 1 ? ct[lr[1]] - ct[lr[0] - 2] : ct[lr[1]];
        }
        WriteLine(string.Join("\n", res));
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