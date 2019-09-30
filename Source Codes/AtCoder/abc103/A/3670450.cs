using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
	    int[] n = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
        Array.Sort(n);
        Console.WriteLine(n[n.Length-1] - n[0]);
	} 
}