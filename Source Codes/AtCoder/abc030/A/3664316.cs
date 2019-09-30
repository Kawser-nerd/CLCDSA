using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
        double[] nums = Console.ReadLine().Split(' ').Select(s => double.Parse(s)).ToArray();
        double a = nums[1]/nums[0];
        double b = nums[3]/nums[2];
        if(a > b)
        {
            Console.WriteLine("TAKAHASHI");
        }
        else if(a < b)
        {
            Console.WriteLine("AOKI");
        }
        else
        {
            Console.WriteLine("DRAW");
        }
    }
}