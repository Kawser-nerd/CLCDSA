using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
        double[] nums = Console.ReadLine().Split(' ').Select(s => double.Parse(s)).ToArray();
        Console.WriteLine((Math.Max(nums[0], nums[1])) * (Math.Min(nums[0],nums[1])+1));
    }
}