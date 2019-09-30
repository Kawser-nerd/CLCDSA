using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace MyProgram{
    public class Program
    {	
        public static void Main(string[] args)
    	{
    	    int n = int.Parse(Console.ReadLine());
    	    
    	    if(n % 2 == 0) Console.WriteLine(n-1);
    	    else Console.WriteLine(n+1);
    	}
    }
}