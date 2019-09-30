using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
	    double now = double.Parse(Console.ReadLine());
        double target = double.Parse(Console.ReadLine());
        double ans = target + (target - now);
        Console.WriteLine(ans);        
	}
}