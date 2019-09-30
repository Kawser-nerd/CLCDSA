using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
        int[] nums = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
        
        int[] list = nums.Distinct().ToArray();
	    Console.WriteLine(list.Length);
	}
}