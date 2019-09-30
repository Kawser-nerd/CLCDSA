using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{   
	    int n = int.Parse(Console.ReadLine());
	    int[] flower = new int[n];
	    flower = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
	    
	    int cnt = 0;
	    
	    for(int i = 0 ; i < n ; i++)
	    {
	        while(flower[i] % 2 == 0 || flower[i] % 3 == 2 )
	        {
	            flower[i]--;
	            cnt++;
	        }
	    }
	    Console.WriteLine(cnt);
	    
	    
	}
}