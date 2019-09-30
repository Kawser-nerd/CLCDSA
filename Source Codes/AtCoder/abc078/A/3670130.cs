using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
	    char[] c = Console.ReadLine().Replace(" ", "").ToCharArray();
	    if(c[0] > c[1]) Console.WriteLine(">");
	    else if(c[0] < c[1]) Console.WriteLine("<");
	    else Console.WriteLine("=");
	    
	} 
}