using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
        int[] nums  = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
        int a = Math.Min(nums[1] , nums[0]);
        Console.WriteLine(nums[2]/a);
	}
}