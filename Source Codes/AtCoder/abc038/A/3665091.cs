using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
        string str = Console.ReadLine();
        if(str[str.Length-1] == 'T') Console.WriteLine("YES");
        else Console.WriteLine("NO");
	}
}