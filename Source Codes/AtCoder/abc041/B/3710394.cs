using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace MyProgram{
    public class Program
    {	
        public static void Main(string[] args)
    	{
    	    long[] nums = Console.ReadLine().Split(' ').Select(s => long.Parse(s)).ToArray();
    	    
    	    long q = (long)Math.Pow(10,9)+7;
    	    long a = nums[0] * nums[1] % q;
    	
    	    Console.WriteLine(a * nums[2] % q);
    	}
    }
}