using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{   
        int n = int.Parse(Console.ReadLine());
        int ans = 99999999;
        for(int i = 0 ; i < n ; i++)
        {
            ans = Math.Min(int.Parse(Console.ReadLine()), ans);
        }
        Console.WriteLine(ans);
	}
}