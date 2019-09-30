using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
	    int[] nums = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
	    
	    int a = nums[0] * nums[1];
	    int b = nums[2] * nums[3];
	    int ans = Math.Max(a,b);
	    Console.WriteLine(ans);
	}
}