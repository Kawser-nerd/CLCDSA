using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
	    int[] nums = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
	    
	    if(nums[0] == 1) nums[0] = 14;
        if(nums[1] == 1) nums[1] = 14;
	
	    if(nums[0] > nums[1])
	    {
	        Console.WriteLine("Alice");
	    }
	    else if(nums[1] > nums[0])
	    {
	        Console.WriteLine("Bob");
	    }
	    else
	    {
	        Console.WriteLine("Draw");
	    }
	}
}