using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{   
        int n = int.Parse(Console.ReadLine());
        long Q = 10007;
	    
	    long[] trib = new long[1000000];
	    trib[0] = 0; trib[1] = 0; trib[2] = 1;
	    if(n > 3)
	    {
	        for(int i = 3 ; i < n ; i++)
	        {
	            trib[i] = (trib[i-1]+trib[i-2]+trib[i-3]) % Q ;
	        }
	    }
	    Console.WriteLine(trib[n-1]);
	}
}