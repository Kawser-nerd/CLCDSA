using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
	    int[] n = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();

	    
	    if(n[0] > n[2]) Console.WriteLine("NO");
	    else if (n[0]+n[1] < n[2] )Console.WriteLine("NO");
	    else Console.WriteLine("YES");
	    
	} 
}