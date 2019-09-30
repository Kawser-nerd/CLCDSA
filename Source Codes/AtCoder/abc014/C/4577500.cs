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
        const int NUM = 1000001;
        var imos = new long[NUM + 1];
        for(var i = 0; i < num; i++)
        {
            var inp = Input.ar;
            imos[inp[0]]++;
            imos[inp[1] + 1]--;
        }
        for (var i = 1; i < NUM; i++)
            imos[i] += imos[i - 1];
        var max = imos[0];
        for (var i = 1; i < NUM; i++)
            max = Max(max, imos[i]);
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