using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace MyProgram{
    public class Program
    {	
        public static void Main(string[] args)
    	{
    	    int now = int.Parse(Console.ReadLine());
    	    int target = int.Parse(Console.ReadLine());
    	    
    	    int a = now;
    	    int b = now;
    	    int cnt1 = 0;
    	    int cnt2 = 0;
    	    while(a != target)
    	    {
    	        a++;
    	        if(a > 9) a = 0;
    	        cnt1++;
    	    }
    	    while(b != target)
    	    {
    	        b--;
    	        if(b < 0) b = 9;
    	        cnt2++;
    	    }
    	    
    	    Console.WriteLine(Math.Min(cnt1,cnt2));
    	    
    	    
    	}
    }
}