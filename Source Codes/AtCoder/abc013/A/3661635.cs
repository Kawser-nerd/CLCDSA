using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class DwangoV
{	
    
    public static void Main()
	{
        string[] str = Console.ReadLine().Split(' ');
        char c =  str[0][0];
        int n = c;
        Console.WriteLine(n-64);
	}
}