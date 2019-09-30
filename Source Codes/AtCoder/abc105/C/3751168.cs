using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class MyProgram
{	
    public static void Main()
	{
	    int N = int.Parse(Console.ReadLine());
	    string ans = "";
	    while(N != 0)
	    {
	        if(N % 2 != 0)
	        {
	            ans = "1" + ans;
	            N = (N-1) / -2;
	        }
	        else
	        {
	            ans = "0" + ans;
	            N /= -2;
	        }
	    }
	    if(ans.Length == 0) Console.WriteLine("0");
	    else Console.WriteLine(ans);
	}
}