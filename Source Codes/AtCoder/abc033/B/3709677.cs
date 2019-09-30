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
    	    string[] name = new string[n];
    	    int[] population = new int[n];
    	    int totalPopulation = 0;
    	    
    	    string ans ="atcoder";
    	    string[] buf;
    	    for(int i = 0 ; i < n ; i++)
    	    {
    	        buf = Console.ReadLine().Split(' ');
    	        name[i] = buf[0];
    	        population[i] = int.Parse(buf[1]);
    	        
    	        totalPopulation += population[i];
    	    }
    	    
    	    for(int i = 0 ; i < n ; i++)
    	    {
    	        if(totalPopulation/2 < population[i])
    	        {
    	            ans = name[i];
    	        }
    	    }
    	    
    	    Console.WriteLine(ans);
    	}
    }
}