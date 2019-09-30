using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
	    string[] s = Console.ReadLine().Split(' ');
	    
	    if(s[0] == "H")
	    {
	        if(s[1]=="H") Console.WriteLine("H");
	        else Console.WriteLine("D");
	    } else if(s[0] == "D")
	    {
	        if(s[1]=="H") Console.WriteLine("D");
	        else Console.WriteLine("H");
	    }
	} 
}