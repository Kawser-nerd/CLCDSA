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
        for(var i = 0; i < 2; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                Console.WriteLine(nums[2 * (1 - i)]);
                break;
            }
            if (nums[i] == nums[i + 2])
            {
                Console.WriteLine(nums[1]);
                break;
            }
        }
    }
}