using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace MyProgram{
    public class Program
    {	
        public static void Main(string[] args)
    	{
    	    double n = double.Parse(Console.ReadLine());
    	    double min = 99999999;
    	    double maxSide = Math.Sqrt(n);
    	    
    	    double tate = 1;
    	    double yoko = 1;
    	    
    	    for(int i = 0 ; i < maxSide ; i++)
    	    {
    	        yoko = tate;
    	        for(int j = 0 ; j < maxSide ; j++)
    	        {
    	            if(tate * yoko <= n)
    	            {
    	                double a = (n - (tate * yoko)) + Math.Abs(tate-yoko);
    	                min = Math.Min(min,a);
    	            }
    	            yoko++;
    	        }
    	        tate++;
    	    }
    	    
    	    Console.WriteLine(min);
    	}
    }
}