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
        var nx = Add.ar;
        var xs = Add.ar;
        xs = xs.Select(v => Abs(v - nx[1])).ToArray();
        var gcd = xs[0];
        for (var i = 1; i < nx[0]; i++)
            gcd = Calculation.GCD(gcd, xs[i]);
        WriteLine(gcd);
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

public class Calculation
{
    public static int LCM(int num1, int num2)
    {
        return num1 / GCD(num1, num2) * num2;
    }

    public static long LCM(long num1, long num2)
    {
        return num1 / GCD(num1, num2) * num2;
    }

    public static int GCD(int num1, int num2)
    {
        return num1 < num2 ? GCD(num2, num1) :
            num2 > 0 ? GCD(num2, num1 % num2) : num1;
    }

    public static long GCD(long num1, long num2)
    {
        return num1 < num2 ? GCD(num2, num1) :
            num2 > 0 ? GCD(num2, num1 % num2) : num1;
    }
}