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
        var hwn = Input.ar;
        var ct = new long[10];
        ct[0] = (long)(hwn[0] - 2) * (hwn[1] - 2);
        var dic = new Dictionary<int, Dictionary<int,int>>();
        for(var i = 0; i < hwn[2]; i++)
        {
            var ab= Input.ar;
            for(var j=0;j<3;j++)
                for(var k = 0; k < 3; k++)
                {
                    var h = ab[0]-1 - j;
                    var w = ab[1]-1 - k;
                    if (h < 0 || h >= hwn[0] - 2 || w < 0 || w >= hwn[1] - 2) continue;
                    if (!dic.ContainsKey(h))
                        dic[h] = new Dictionary<int, int>();
                    if (dic[h].ContainsKey(w))
                        dic[h][w]++;
                    else dic[h][w] = 1;
                    ct[dic[h][w] - 1]--;
                    ct[dic[h][w]]++;
                }
        }
        WriteLine(string.Join("\n", ct));
    }
}

public class Input
{
    public static string read => ReadLine();
    public  static int[] ar => Array.ConvertAll(read.Split(' '), int.Parse);
    public  static int num => ToInt32(read);
    public static long[] arL => Array.ConvertAll(read.Split(' '), long.Parse);
    public  static long numL => ToInt64(read);
    public static int[][] twodim(int num)
        => Enumerable.Repeat(0, num).Select(v => ar).ToArray();
    public static long[][] twodimL(int num)
        => Enumerable.Repeat(0, num).Select(v => arL).ToArray();
    public  const string Alfa = "abcdefghijklmnopqrstuvwxyz";
    public  const int MOD = 1000000007;
}