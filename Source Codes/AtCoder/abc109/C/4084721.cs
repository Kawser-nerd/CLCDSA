using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var nx = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var ar = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        for (var i = 0; i < nx[0]; i++)
            ar[i] = Abs(nx[1] - ar[i]);
        var gc = 0;
        for(var i = 0; i < nx[0]; i++)
        {
            if (gc == 0 && ar[i] != 0) gc = ar[i];
            else if (gc != 0 && ar[i] != 0) gc = Calculation.GCD(gc, ar[i]);
        }
        WriteLine(gc);
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}
public class Calculation
{
  public static int GCD(int num1, int num2)
    {
        return num1 < num2 ? GCD(num2, num1) :
            num2 > 0 ? GCD(num2, num1 % num2) : num1;
    }
}