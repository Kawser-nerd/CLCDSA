using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{   
        string s = Console.ReadLine();
        string[] c = new string[5] { "a", "i" , "u", "e", "o" };
        for(int i = 0 ; i < c.Length ; i++)
        {
          s = s.Replace(c[i],"");   
        }

        Console.WriteLine(s);
	}
}