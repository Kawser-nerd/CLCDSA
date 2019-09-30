using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class DwangoV
{	
    
    public static void Main()
	{
        int[] nums = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
        if(nums[0]%nums[1] == 0) Console.WriteLine("YES");
        else Console.WriteLine("NO");
	}
}