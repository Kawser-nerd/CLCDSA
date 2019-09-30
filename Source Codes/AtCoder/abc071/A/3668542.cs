using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
	    int[] nums = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
        
        int a = Math.Abs(nums[0]-nums[1]);
        int b = Math.Abs(nums[0]-nums[2]);
        if(a < b) Console.WriteLine("A");
        else Console.WriteLine("B");
        
	}
}