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
        var frto = new long[nm[0]][];
        for (var i = 0; i < nm[0]; i++)
            frto[i] = new long[nm[0]];
        for (var i = 0; i < nm[0]; i++)
            for (var j = 0; j < nm[0]; j++)
                if (i != j)
                    frto[i][j] = int.MaxValue;
        for(var i = 0; i < nm[1]; i++)
        {
            var inp = Input.ar;
            frto[inp[0] - 1][inp[1] - 1] = inp[2];
            frto[inp[1] - 1][inp[0] - 1] = inp[2];
        }
        for (var k = 0; k < nm[0]; k++)
            for (var i = 0; i < nm[0]; i++)
                for (var j = 0; j < nm[0]; j++)
                    frto[i][j] = Min(frto[i][j], frto[i][k] + frto[k][j]);
        var min = (long)int.MaxValue;
        for (var i = 0; i < nm[0]; i++)
            min = Min(min, frto[i].Where(v=>v!=int.MaxValue).Max());
        WriteLine(min);
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