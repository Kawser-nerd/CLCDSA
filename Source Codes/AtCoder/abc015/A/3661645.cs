using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class DwangoV
{	
    
    public static void Main()
	{
        string str1 = Console.ReadLine();
        string str2 = Console.ReadLine();
        if(str1.Length > str2.Length) Console.WriteLine(str1);
        else Console.WriteLine(str2);
	}
}