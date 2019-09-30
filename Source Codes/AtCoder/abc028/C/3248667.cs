using static AddFunction;
using System;
using System.Collections.Generic;
using static System.Console;
using static System.Convert;

class Program
{
    static void Main(string[] args)
    {
        var nums = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var num1 = new[] { 0, 0, 0, 0, 0, 0, 1, 1, 1, 2 };
        var num2 = new[] { 1, 1, 1, 2, 2, 3, 2, 2, 3, 3 };
        var num3 = new[] { 2, 3, 4, 3, 4, 4, 3, 4, 4, 4 };
        var array = new int[Combination(5, 3)];
        for(var i = 0; i < Combination(5, 3); i++)
        {
            array[i] = nums[num1[i]] + nums[num2[i]] + nums[num3[i]];
        }
        Array.Sort(array);
        WriteLine(array[7]);
    }
}

public static class AddFunction
{
    public static int Combination(int num1,int num2)
    {
        var p1 = num1;
        var p2 = num2;
        for(var i = 1; i < num2; i++)
        {
            p1 *= num1 - i;
            p2 *= num2 - i;
        }
        return p1 / p2;
    }
}