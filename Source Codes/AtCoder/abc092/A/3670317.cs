using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{   
	    int[] nums = new int[4]; 
	    for(int i = 0 ; i <4 ; i++) nums[i] = int.Parse(Console.ReadLine()); 
        Console.WriteLine(Math.Min(nums[0],nums[1]) + Math.Min(nums[2],nums[3]) );
	}
}