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
        var nk = Add.ar;
        var res = 0L;
        for(var i = 1; i <= nk[0]; i++)
        {
            res += nk[0] / i * Max(0, i - nk[1]);
            res += Max(0, nk[0] % i - nk[1] + 1);
        }
        WriteLine(res - (nk[1] == 0 ? nk[0] : 0));
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