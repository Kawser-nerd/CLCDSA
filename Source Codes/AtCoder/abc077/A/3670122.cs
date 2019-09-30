using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
	    string s1 = Console.ReadLine();
	    string s2 = Console.ReadLine();
	    bool ok = true;
	    
	    for(int i = 0; i < s1.Length ; i++)
	    {
	        if(s1[i] != s2[s2.Length-1 -i]) ok = false;
	    }
	    
	    if(ok)
	    {
	        Console.WriteLine("YES");
	    }
	    else Console.WriteLine("NO");
	    
	} 
}