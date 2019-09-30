using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
        string[] str = Console.ReadLine().Split(' ');

        if(str[0] == str[1])
        {
            Console.WriteLine(str[2]);
        }
        else if(str[0] == str[2])
        {
            Console.WriteLine(str[1]);
        }
        else
        {
            Console.WriteLine(str[0]);
        }
        
    }
}