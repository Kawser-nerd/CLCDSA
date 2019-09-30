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
        var hs = Enumerable.Repeat(0, num).Select(v=>Input.ar).ToArray();
        var left = 0L;
        var right = hs.Max(ar => ar[0] + (long)ar[1] * num);
        while (right > left)
        {
            var mid = (right + left) / 2;
            var isSh = true;
            var ct = new int[num];
            for (var i = 0; i < num; i++)
                if (hs[i][0] <= mid)
                {
                    var time = (mid - hs[i][0]) / hs[i][1];
                    ct[Min(num - 1, time)]++;
                }
                else { isSh = false; break; }
            for (var i = 1; i < num; i++)
                ct[i] += ct[i - 1];
            for (var i = 0; i < num; i++)
                if (isSh)
                    isSh = ct[i] <= i + 1;
                else break;
            if (isSh) right = mid;
            else left = mid + 1;
        }
        WriteLine(left);
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