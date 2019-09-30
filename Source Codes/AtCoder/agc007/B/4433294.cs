using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
//using static System.Globalization.CultureInfo;

class Program
{
    static void Main(string[] args)
    {
        var num = Add.num;
        var ps = Add.ar;
        var r = new int[num];
        for (var i = 0; i < num; i++)
            r[ps[i] - 1] = i + 1;
        var a = Enumerable.Range(1, num).Select(v => v * 30000).ToArray();
        var b = Enumerable.Range(1, num).Select(v => (num - v) * 30000 + r[v - 1]).ToArray();
        WriteLine($"{string.Join(" ", a)}\n{string.Join(" ", b)}");
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