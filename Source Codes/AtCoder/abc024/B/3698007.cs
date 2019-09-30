using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace MyProgram{
    public class Program
    {	
        public static void Main(string[] args)
    	{
    	    int[] nums = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
    	    int n = nums[0];
    	    int T = nums[1];
    	    
    	    int openTime = int.Parse(Console.ReadLine());
    	    int closeTime = openTime+T;
    	    
    	    int ans = 0;
    	    int time = 0;
    	    
    	    for(int i = 1 ; i < n ; i++)
    	    {
    	        time = int.Parse(Console.ReadLine());
    	        
    	        if(openTime <= time && time <= closeTime)
    	        {
    	            closeTime = time+T;
    	            
    	        }
    	        else if(time >= closeTime)
    	        {

    	            ans += closeTime - openTime;
    	            openTime = time;
    	            closeTime = openTime+T;
    	          
    	        }
        	    if(i == n-1)
    	        {
                    ans += closeTime - openTime;   
    	           
    	        }
    	    }
    	    Console.WriteLine(ans);
    	}
    }
}