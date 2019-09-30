using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace MyProgram{
    public class Program
    {	
        public static void Main(string[] args)
    	{
    	    double X = double.Parse(Console.ReadLine());
    	    
    	    double n = Math.Sqrt(X);
    	    n = Math.Sqrt(n);
    	    Console.WriteLine(n);
    	}
    }
}