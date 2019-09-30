using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
	    int[] n = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
        if(n[0]%n[1] > 0) Console.WriteLine(1);
	    else Console.WriteLine(0);
	    
	} 
}