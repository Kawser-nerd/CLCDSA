using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
	    int[] a = new int[7] {1,3,5,7,8,10,12};
	    int[] b = new int[4] {4,6,9,11};
	    int[] c = new int[1] {1};
	    int[] nums = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
	    int x = nums[0];
	    int y = nums[1];
	    
	    if(a.Contains(x)) x = 111;
	    if(b.Contains(x)) x = 222;
        if(c.Contains(x)) x = 333;
        if(a.Contains(y)) y = 111;
	    if(b.Contains(y)) y = 222;
        if(c.Contains(y)) y = 333;
        
        if(x==y) Console.WriteLine("Yes");
        else Console.WriteLine("No");
	} 
}