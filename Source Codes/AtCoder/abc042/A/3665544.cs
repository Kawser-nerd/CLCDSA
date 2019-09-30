using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
        int[] nums = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
        Array.Sort(nums);
        bool ok = true;
        if(nums[0] != 5) ok = false;
        if(nums[1] != 5) ok = false;
        if(nums[2] != 7) ok = false;
        
        if(ok) Console.WriteLine("YES");
        else Console.WriteLine("NO");
	}
}