using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
	    int[] nums = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();

        int[] ans = new int[3];
        ans[0] = nums[0] + nums[1];
        ans[1] = nums[0] + nums[2];
        ans[2] = nums[1] + nums[2];
        Array.Sort(ans);
        
        Console.WriteLine(ans[0]);
        
	}
}