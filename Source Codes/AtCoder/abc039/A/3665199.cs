using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
        int[] nums = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
        int a = nums[0] * nums[1] * 2;
        int b = nums[0] * nums[2] * 2;
        int c = nums[1] * nums[2] * 2;
        Console.WriteLine(a+b+c);
	}
}