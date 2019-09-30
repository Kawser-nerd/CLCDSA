using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
	    double [] n = Console.ReadLine().Split(' ').Select(s=>double.Parse(s)).ToArray();
	    Console.WriteLine(  Math.Ceiling((n[0]+n[1])/2));
	} 
}