using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
        int n = int.Parse(Console.ReadLine());
        
        if(n == 100)
        {
            Console.WriteLine("Perfect");
        } 
        else if(n <= 99 && n>=90)
        {
            Console.WriteLine("Great");
        }
        else if(89 >= n && n >= 60)
        {
            Console.WriteLine("Good");
        }
        else
        {
            Console.WriteLine("Bad");
        }
    }
}