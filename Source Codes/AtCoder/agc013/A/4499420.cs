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
        var ar = Input.ar;
        var list = new List<int>() { ar[0] };
        for (var i = 1; i < num; i++)
            if (list[list.Count - 1] != ar[i])
                list.Add(ar[i]);
        if (list.Count == 1)
        {
            WriteLine(1);
            return;
        }
        var ct = 1;
        var isInc = list[0] < list[1];
        for(var i = 1; i < list.Count-1; i++)
        {
            if ((isInc && list[i] > list[i + 1]) || (!isInc && list[i] < list[i + 1]))
            {
                i++;
                ct++;
            }
            if(i+1<list.Count)
            isInc = list[i] < list[i + 1];
        }
        WriteLine(ct);
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