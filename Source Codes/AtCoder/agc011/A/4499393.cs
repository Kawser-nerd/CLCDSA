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
        var nck = Input.ar;
        var time = new int[nck[0]];
        for (var i = 0; i < nck[0]; i++)
            time[i] = Input.num;
        Array.Sort(time);
        var ct = 1;
        var bus = 1;
        var index = 1;
        var t = time[0] + nck[2];
        while (index != nck[0])
        {
            var val = time[index];
            index++;
            if (ct+1 > nck[1] || val> t)
            {
                ct = 1;
                bus++;
                t = val + nck[2];
            }
            else
                ct++;
        }
        WriteLine(bus);
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