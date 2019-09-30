using System;

class Program
{
    static void Main(string[] args)
    {
        var input = Console.ReadLine();
        var nums = new int[2];
        for(int i = 0; i < 2; i++)
        {
            nums[i] = Convert.ToInt32(input.Substring(i, 1));
        }
        Console.WriteLine($"{nums[0] + nums[1]}");
    }
}