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
        Array.Sort(nums);
        var result = nums[0] + nums[1] == nums[2] ? "Yes" : "No";
        Console.WriteLine(result);
    }
}