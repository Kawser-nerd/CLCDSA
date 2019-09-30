using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
        int[] test = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
        if(test[0] < test[1]) Console.WriteLine("Better");
        else Console.WriteLine("Worse");
	}
}