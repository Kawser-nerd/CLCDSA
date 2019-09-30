using System;
using System.Collections.Generic;
using static System.Console;
using static System.Convert;

class Program
{
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        var nums = Array.ConvertAll(ReadLine().Split(' '), ulong.Parse);
        var set = new HashSet<ulong>();
        for(var i = 0; i < num; i++)
        {
            while (nums[i] % 2 == 0)
            {
                nums[i] /= 2;
            }
            set.Add(nums[i]);
        }
        WriteLine(set.Count);
    }
}