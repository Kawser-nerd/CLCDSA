using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
	    string s = Console.ReadLine();
	    if(s[0] == s[s.Length-1]) Console.WriteLine("Yes");
	    else Console.WriteLine("No");
	} 
}