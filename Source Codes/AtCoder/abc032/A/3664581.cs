using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
        int a = int.Parse(Console.ReadLine());
        int b = int.Parse(Console.ReadLine());
        int n = int.Parse(Console.ReadLine());
    
	    while(true)
	    {
	        if(n%a==0 && n%b==0)
	        {
	            Console.WriteLine(n);
	            break;
	        }
	        n++;
	    }
	    
	}
}