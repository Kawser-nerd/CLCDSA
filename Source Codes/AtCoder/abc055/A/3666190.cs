using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
	    int[] nums = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
	    
	    int a = nums[0];
	    int b = nums[0]/15;
	    
	    Console.WriteLine(a*800 - b*200);
	    
	}
}