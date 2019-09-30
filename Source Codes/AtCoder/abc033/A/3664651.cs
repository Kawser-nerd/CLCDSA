using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
        char[] c = Console.ReadLine().ToCharArray();
        bool same = true;
        
        for(int i = 0 ; i < c.Length ; i++)
        {
            for(int j = i ; j < c.Length ; j++)
            {
                if(c[i] != c[j]) same = false;
            }
        }
        
        if(same) Console.WriteLine("SAME");
        else Console.WriteLine("DIFFERENT");
	}
}