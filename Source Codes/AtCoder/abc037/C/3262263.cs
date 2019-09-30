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
        var input = ReadLine().Split(' ');
        var num = ToInt32(input[0]);
        var select = ToInt32(input[1]);
        var nums = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var sums = new long[num];
        for(var i = 0; i < num; i++)
        {
            if (i == 0) sums[i] = nums[i];
            else sums[i] = sums[i - 1] + nums[i];
        }
        long result = 0;
        for(var i = 0; i < num-select+1; i++)
        {
            if (i == 0) result += sums[select - 1];
            else result += sums[i + select-1] -sums[i-1];
        }
        WriteLine(result);
    }
}