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
        if (num <=2)
        {
            WriteLine(3 * num);
            return;
        }
        var str1 = ReadLine();
        var str2 = ReadLine();
        var res = 6L;
        for(var i = str1[2]==str1[1]?3:2; i < num; i++)
        {
            if (str1[i] == str2[i])
            {
                if (str1[i - 1] != str1[i - 2]) res *= 2;
            }
            else
            {
                if (str1[i - 1] == str1[i - 2]) res *= 3;
                else res *= 2;
                    i++;
            }
            res %= Input.MOD;
        }
        WriteLine(res);
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
    public const double eps = 1e-11;
    public  const string Alfa = "abcdefghijklmnopqrstuvwxyz";
    public  const int MOD = 1000000007;
}