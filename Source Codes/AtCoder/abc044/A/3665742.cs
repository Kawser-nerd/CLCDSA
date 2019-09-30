using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
        int n = int.Parse(Console.ReadLine());
        int k = int.Parse(Console.ReadLine());
        int x = int.Parse(Console.ReadLine());
        int y = int.Parse(Console.ReadLine());
	
	    int ans = 0;
	    for(int i = 0 ; i < n ; i++)
	    {
	        if(i < k) ans += x;
	        else ans += y;
	    }
	    Console.WriteLine(ans);
	}
}