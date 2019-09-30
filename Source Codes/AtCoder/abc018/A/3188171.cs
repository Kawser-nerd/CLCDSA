using System;

class Program
{
    static void Main(string[] args)
    {
        var nums = new int[3];
        for (int i = 0; i < 3; i++)
        {
            nums[i] = Convert.ToInt32(Console.ReadLine());
        }

        var max = Math.Max(nums[0], nums[1]);
        max = Math.Max(max, nums[2]);
        var min = Math.Min(nums[0], nums[1]);
        min = Math.Min(min, nums[2]);
        var maxNum = -1;
        var minNum = -1;
        var middleNum = -1;
        for(int i = 0; i < 3; i++)
        {
            if (max == nums[i]) maxNum=i;
            if (min == nums[i]) minNum = i;
        }
        for(int i = 0; i < 3; i++)
        {
            if (i != maxNum && i != minNum) middleNum = i;
        }
        for(int i = 0; i < 3; i++)
        {
            if (i == maxNum) Console.WriteLine(1);
            if (i == middleNum) Console.WriteLine(2);
            if (i == minNum) Console.WriteLine(3);
        }
        
    }
}