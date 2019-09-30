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
        var rck = Input.ar;
        var gred = new string[rck[0]];
        for (var i = 0; i < rck[0]; i++)
            gred[i] = ReadLine();
        var len = new int[rck[0]+1, rck[1]+1];
        for (var i = 1; i <= rck[0]; i++)
            for (var j = 1; j <= rck[1]; j++)
                if (gred[i - 1][j - 1] == 'o')
                    len[i, j] = len[i, j-1] + 1;
                else len[i, j] = 0;
        var res = 0;
        for(var i = 0; i <= rck[0] - 2 * rck[2] + 1; i++)
        {
            for (var j = rck[2] - 1; j < rck[1]-rck[2]+1; j++)
            {
                var c = 1;
                var ish = true;
                for (var r = i; r < i + 2 * rck[2]-1; r++)
                {
                    if (ish && len[r + 1, j + c / 2 + 1] < c)
                        ish = false;
                    if (r < i + rck[2]-1)
                        c += 2;
                    else c -= 2;
                }
                if (ish) res++;
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