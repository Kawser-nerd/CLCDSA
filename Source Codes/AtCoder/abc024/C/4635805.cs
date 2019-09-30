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
        var ndk = Input.ar;
        var lr = Input.twodim(ndk[1]);
        var st = Input.twodim(ndk[2]);
        for(var i = 0; i < ndk[2]; i++)
            for (var j = 0; j < ndk[1]; j++)
            {
                if (lr[j][0] > st[i][0] || lr[j][1] < st[i][0]) continue;
                if (lr[j][0] <= st[i][1] && st[i][1] <= lr[j][1])
                {
                    WriteLine(j + 1);
                    break;
                }
                else if (st[i][1] < lr[j][0]) st[i][0] = lr[j][0];
                else st[i][0] = lr[j][1];
            }
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