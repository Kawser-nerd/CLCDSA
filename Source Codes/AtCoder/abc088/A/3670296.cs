using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
	    int n = int.Parse(Console.ReadLine());
	    int a = int.Parse(Console.ReadLine());
	    if(n%500 <= a) Console.WriteLine("Yes");
	    else Console.WriteLine("No");
	} 
}