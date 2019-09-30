using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
	    char[] c = Console.ReadLine().Replace(" ", "").ToCharArray();
	    bool ok = false;
	    if(c[0] == c[1] && c[1] == c[2]) ok = true;
	    if(c[1] == c[2] && c[2] == c[3]) ok = true;
	    
	    if(ok) Console.WriteLine("Yes");
	    else Console.WriteLine("No");
	} 
}