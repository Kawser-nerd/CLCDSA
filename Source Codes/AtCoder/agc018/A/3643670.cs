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
        var nk = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var ar = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        for(var i=0;i<nk[0];i++)
            if (nk[1] == ar[i]) { WriteLine("POSSIBLE");return; }
        if (ar.Max() < nk[1]) { WriteLine("IMPOSSIBLE");return; }
        var g = Calculation.GCD(ar[0], ar[1]);
        for (var i = 2; i < nk[0]; i++)
        {
            g = Calculation.GCD(g, ar[i]);
            if (g == 1) break;
        }
        WriteLine(nk[1] % g == 0 ? "POSSIBLE" : "IMPOSSIBLE");
    }
}
public class Calculation
{
public static int GCD(int num1, int num2)
    {
        return num1 < num2 ? GCD(num2, num1) :
            num2 > 0 ? GCD(num2, num1 % num2) : num1;
    }
}