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
        var ng = new int[3];
        for (var i = 0; i < 3; i++)
            ng[i] = ToInt32(ReadLine());
        if (ng.Contains(num)) { WriteLine("NO");return; }
        if (num <= 3) { WriteLine("YES");return; }
        var k = new int[num + 1];
        for (var i = 0; i <= num; i++)
            k[i] = 10000;
        k[num] = 0;
        if(!ng.Contains(num-1))k[num-1] = 1;
        if(!ng.Contains(num-2))k[num-2] = 1;
        var index = 3;
        while (index != num+1)
        {
            if (!ng.Contains(num - index))
                k[num - index] = Calculation.Min(k[num - index + 1], k[num - index + 2], k[num - index + 3]) + 1;
            index++;
        }
        WriteLine(k[0] <= 100 ? "YES" : "NO");
    }

    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}

public class Calculation
{
    public static int Min(params int[] nums)
    {
        var min = int.MaxValue;
        for (var i = 0; i < nums.Length; i++)
            min = Math.Min(min, nums[i]);
        return min;
    }

}