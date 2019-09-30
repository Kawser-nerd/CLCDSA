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
        var ct = Enumerable.Repeat(1, nm[0]).ToArray();
        var bo = new bool[nm[0]];
        bo[0] = true;
        for(var i = 0; i < nm[1]; i++)
        {
            var xy = Input.ar;
            ct[xy[0]-1]--;
            ct[xy[1]-1]++;
            bo[xy[1] - 1] = bo[xy[1] - 1] || bo[xy[0] - 1];
            bo[xy[0] - 1] = ct[xy[0] - 1] != 0 && bo[xy[0] - 1];
        }
        WriteLine(bo.Count(b => b));
    }
}

public class Input
{
    public static string read => ReadLine();
    public  static int[] ar => Array.ConvertAll(read.Split(' '), int.Parse);
    public  static int num => ToInt32(read);
    public  
static long[] arL => Array.ConvertAll(read.Split(' '), long.Parse);
    public  static long numL => ToInt64(read);
    public static int[][] twodim(int num)
        => Enumerable.Repeat(0, num).Select(v => ar).ToArray();
    public static long[][] twodimL(int num)
        => Enumerable.Repeat(0, num).Select(v => arL).ToArray();
    public  const string Alfa = "abcdefghijklmnopqrstuvwxyz";
    public  const int MOD = 1000000007;
}