using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace MyProgram{
    public class Program
    {	
        public static void Main(string[] args)
    	{
    	    int[] disp1 = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            int[] disp2 = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();   	    
    	
    	    if(disp1[0] == disp2[0] || disp1[0] == disp2[1] || disp1[1] == disp2[0] || disp1[1] == disp2[1])
    	    {
    	        Console.WriteLine("YES");
    	    }
    	    else
    	    {
    	        Console.WriteLine("NO");
    	    }
    	}
    }
}