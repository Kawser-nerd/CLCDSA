using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace MyProgram{
    public class Program
    {	
        public static void Main(string[] args)
    	{
    	    int[] nums = Console.ReadLine().Split(' ').Select(s=>int.Parse(s)).ToArray();
    	    int n = nums[0];
    	    int X = nums[1];
    	    int[] items = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
    	    string sss = Convert.ToString(X,2);
    	    sss = sss.PadLeft(n,'0');
    	    int ans = 0;
    	    
    	    for(int i = 0; i < n ; i++)
    	    {
    	        if(sss[n-i-1] == '1')
    	        {
    	            ans += items[i];
    	        }
    	    }
    	    Console.WriteLine(ans);
    	    
    	}
    }
}