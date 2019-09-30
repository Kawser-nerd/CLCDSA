using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class DwangoV
{	
    
    public static void Main()
	{
        string[] str = Console.ReadLine().Split(' ');
        int x = int.Parse(str[0]);
        int y = int.Parse(str[1]);
        Console.WriteLine(y-x+1);
	}
}