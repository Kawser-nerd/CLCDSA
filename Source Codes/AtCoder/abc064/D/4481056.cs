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
        var str = ReadLine();
        var left = 0;
        var res = "";
        for(var i = 0; i < num; i++)
        {
            if(str[i]==')')
            {
                if (left > 0)
                    left--;
                else
                    res = "(" + res;
                res += ")";
            }
            else
            {
                left++;
                res += "(";
            }
        }
        for (var i = 0; i < left; i++)
            res += ")";
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