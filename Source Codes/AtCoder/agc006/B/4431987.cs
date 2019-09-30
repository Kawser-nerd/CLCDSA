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
        var nx = Add.ar;
        if (nx[1] == 1 || nx[1] == 2 * nx[0] - 1)
        {
            WriteLine("No"); return;
        }
        if (nx[0] == 2)
        {
            WriteLine($"Yes\n{string.Join("\n", Enumerable.Range(1, 3))}");
            return;
        }

        var res = Enumerable.Range(1, 2 * nx[0] - 1).ToArray();
        var ar = new int[4];
        if (nx[1] != 2)
            ar = new[] { nx[1] - 1, nx[1], nx[1] + 1, nx[1] - 2 };
        else
            ar = new[] { nx[1] + 1, nx[1], nx[1] - 1, nx[1] + 2 };
        for (var i = 0; i < 4; i++)
            if (ar[i] != res[nx[0]+i-2])
            {
                var index = res.ToList().IndexOf(ar[i]);
                var t = res[index];
                res[index] = res[nx[0] + i - 2];
                res[nx[0] + i - 2] = t;
            }
        
        WriteLine($"Yes\n{string.Join("\n", res)}");
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