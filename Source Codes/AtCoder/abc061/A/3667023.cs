using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
	    int[] nums = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
	    
	    if(nums[0] <= nums[2] && nums[2] <= nums[1])
	    {
	        Console.WriteLine("Yes");
	    }
	    else
	    {
	        Console.WriteLine("No");
	    }
	} 
}