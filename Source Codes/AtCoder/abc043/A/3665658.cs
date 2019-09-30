using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
        int[] nums = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
        int n = nums[0];
        
        /*
        int a = 0;
        for(int i = 1 ; i<=n ; i++) a += i;
        Console.WriteLine(a);
        */
        Console.WriteLine(((n+1)*n)/2);
	}
}