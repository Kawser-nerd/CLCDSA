using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
	    int[] n = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
        if(Math.Abs(n[0]-n[2]) <= n[3]) Console.WriteLine("Yes");
        else if (Math.Abs(n[0]-n[1]) <= n[3] && Math.Abs(n[1]-n[2]) <= n[3])
        {
            Console.WriteLine("Yes");
        }
        else Console.WriteLine("No");
	} 
}