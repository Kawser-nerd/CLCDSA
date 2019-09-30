using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
	    int[] hasira = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
	    Array.Sort(hasira);
	    if(hasira[1] - hasira[0] == hasira[2] - hasira[1])
	    {
	        Console.WriteLine("YES");
	    }
	    else
	    {
	        Console.WriteLine("NO");
	    }
	    
	} 
}