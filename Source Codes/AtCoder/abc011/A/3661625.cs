using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class DwangoV
{	
    
    public static void Main()
	{
        string[] str = Console.ReadLine().Split(' ');
        int n = int.Parse(str[0]);
        Console.WriteLine(n%12+1);
	}
}