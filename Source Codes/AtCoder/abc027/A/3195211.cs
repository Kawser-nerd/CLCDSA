using System;

class Program
{
    static void Main(string[] args)
    {
        var input = Console.ReadLine().Split(' ');
        var nums = new int[3];
        for(var i = 0; i < 3; i++)
        {
            nums[i] = Convert.ToInt32(input[i]);
        }

        var fig = nums[0];
        var count=Array.LastIndexOf(nums, nums[0]);
        if (count != 0) fig = nums[Math.Abs(count - 3)];
        Console.WriteLine(fig);
    }
}