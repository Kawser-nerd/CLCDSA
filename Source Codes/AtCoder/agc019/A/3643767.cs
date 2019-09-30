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
        var qhsd = Array.ConvertAll(ReadLine().Split(' '), long.Parse);
        var num = ToInt32(ReadLine());
        var l2 = Calculation.Min(qhsd[3], 2 * qhsd[2], 4 * qhsd[1], 8 * qhsd[0]);
        var l1 = Calculation.Min(qhsd[2], 2 * qhsd[1], 4 * qhsd[0]);
        WriteLine((long)num / 2 * l2 + num % 2 * l1);
    }
}

public class Calculation
{
    public static long Min(params long[] nums)
    {
        var min = long.MaxValue;
        for (var i = 0; i < nums.Length; i++)
            min = Math.Min(min, nums[i]);
        return min;
    }
}