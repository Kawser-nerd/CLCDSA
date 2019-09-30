using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
	    int num = int.Parse(Console.ReadLine());
        double a = Math.Pow(num,2);
        num = int.Parse(Console.ReadLine());
        Console.WriteLine(a-num);        
	}
}