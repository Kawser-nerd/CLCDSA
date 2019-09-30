using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace MyProgram{
    public class Program
    {	
        public static void Main(string[] args)
    	{
    	    ?int n = int.Parse(Console.ReadLine());
    	    ?double[] circle = new double[n];
    	    ?
    	    ?double d = 0;
    	    ?for(int i = 0 ; i < n ; i++)
    	    ?{
    	    ?    d = double.Parse(Console.ReadLine());
    	    ?    circle[i] = Math.Pow(d,2);
    	    ?}
    	    ?Array.Sort(circle);
    	    ?
    	    ?d = 0;
    	    ?bool red = true;
    	    ?for(int i = n-1 ; i >= 0 ; i--)
    	    ?{
    	    ?    if(red)
    	    ?    {
    	    ?        d += circle[i];
    	    ?        red = false;
    	    ?    }
    	    ?    else
    	    ?    {
    	    ?        d -= circle[i];
    	    ?        red = true;
    	    ?    }
    	    ?}
    	    ?Console.WriteLine(d * Math.PI);
    	}
    }
}