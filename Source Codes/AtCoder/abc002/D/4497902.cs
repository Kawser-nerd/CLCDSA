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
        var adj = new bool[nm[0], nm[0]];
        for(var i = 0; i < nm[1]; i++)
        {
            var ad = Input.ar;
            adj[ad[0] - 1, ad[1] - 1] = true;
            adj[ad[1] - 1, ad[0] - 1] = true;
        }
        var res = 0;
        for(var i = 1; i < (1 << nm[0]); i++)
        {
            var list = new List<int>();
            for (var j = 0; j < nm[0]; j++)
                if ((1 & i >> j) == 1)
                    list.Add(j);
            var isFri = true;
            foreach (var vex in list)
            {
                foreach (var ad in list)
                {
                    if (vex == ad) continue;
                    if (isFri && !adj[vex, ad])
                        isFri = false;
                    else if (!isFri) break;
                }
                if (!isFri) break;
            }
            if (isFri) res = Max(res, list.Count);
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