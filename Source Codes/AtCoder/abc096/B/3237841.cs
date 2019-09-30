using System;
using static System.Console;
using static System.Convert;

class Program
{
    static void Main(string[] args)
    {
        var nums = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var count = ToInt32(ReadLine());
        Array.Sort(nums);
        for(var i = 0; i < count; i++)
        {
            nums[2] *= 2;
        }
        WriteLine(nums[0] + nums[1] + nums[2]);
    }
}