using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{   
	    int n = int.Parse(Console.ReadLine());
	    if(n%2 == 0) Console.WriteLine(n);
	    else Console.WriteLine(n*2);
	}
}