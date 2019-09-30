using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    
    public static void Main()
	{
	    double ans = 0;
	    double[] nums;
        for(int i = 0 ; i < 3 ; i++)
        {
            nums = Console.ReadLine().Split(' ').Select(s => double.Parse(s)).ToArray();
            ans += nums[0] * (nums[1] / 10);
        }
        Console.WriteLine(ans);
	}
}