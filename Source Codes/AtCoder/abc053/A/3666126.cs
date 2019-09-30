using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
	    int[] nums = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
	    
	    if(nums[0] < 1200) Console.WriteLine("ABC");
	    else Console.WriteLine("ARC");
	}
}