using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{   
	    string s = Console.ReadLine();
	    if(s.Contains("a") && s.Contains("b") && s.Contains("c"))
	    {
	        Console.WriteLine("Yes");
	    }
	    else
	    {
	        Console.WriteLine("No");
	    }
	}
}