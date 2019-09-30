using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        var input = Console.ReadLine().Split(' ');
        var nums = new List<int>();
        for (var i = 0; i < 3; i++)
        {
            nums.Add(Convert.ToInt32(input[i]));
        }
        nums.Sort();
        Console.WriteLine(nums[1]);
    }
}