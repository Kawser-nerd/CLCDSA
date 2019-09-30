using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
	    string s = Console.ReadLine();
	    s = s.Replace(" ", "");
	    int n = int.Parse(s);
	    
	    if(n%4 == 0) Console.WriteLine("YES");
	    else Console.WriteLine("NO");
	} 
}