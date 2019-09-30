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
        var nabcd = Add.arL;
        for(var i = 0; i < nabcd[0]; i++)
        {
            var min = (nabcd[0] - 1 - i) * nabcd[3] - i * nabcd[4];
            var max = -i * nabcd[3] + (nabcd[0] - 1 - i) * nabcd[4];
            var dis = nabcd[2] - nabcd[1];
            if (min <= dis && dis <= max)
            {
                WriteLine("YES");
                return;
            }
        }
        WriteLine("NO");
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