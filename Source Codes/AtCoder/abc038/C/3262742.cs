using static AddFunction;
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
        var num = ToInt32(ReadLine());
        var seq = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var last = 0;
        double result = num;
        for (var i = 0; i < num; i++)
        {
            if (i == 0) continue;
            if (seq[i] <= seq[i - 1]) { result +=Combination((double)i-last,2); last = i; }
            else if (i == num - 1) result += Combination(i-last+1,2);
        }
        WriteLine(result);
    }
}

public static class AddFunction
{
  public static double Combination(double num1,double num2)
    {
        if (num1 < num2) return 0;
        var p1 = num1;
        var p2 = num2;
        for (var i = 1; i < num2; i++)
        {
            p1 *= num1 - i;
            p2 *= num2 - i;
        }
        return p1 / p2;
    }
}