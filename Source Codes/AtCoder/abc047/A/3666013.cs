using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
        int[] nums = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
        
        bool ok = false;
        if(nums[0]+nums[1] == nums[2]) ok = true;
        if(nums[1]+nums[2] == nums[0]) ok = true;
        if(nums[0]+nums[2] == nums[1]) ok = true;
        
        if(ok) Console.WriteLine("Yes");
        else Console.WriteLine("No");
	}
}