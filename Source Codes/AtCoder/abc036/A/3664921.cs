using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
        int[] nums  = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
        int ans = nums[1] / nums[0];
        if(nums[1] % nums[0] > 0) ans++;
        Console.WriteLine(ans);
	}
}