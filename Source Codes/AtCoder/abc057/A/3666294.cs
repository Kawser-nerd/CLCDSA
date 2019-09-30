using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
	    int[] time = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
	    
	    int ans = (time[0] + time[1])%24;
	    Console.WriteLine(ans);
	    
	} 
}