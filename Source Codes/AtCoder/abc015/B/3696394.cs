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
    	    double[] nums = Console.ReadLine().Split(' ').Select(s=>double.Parse(s)).ToArray();
            
            double cnt = 0;
            double sum = 0;
            for(int i = 0 ; i < n ; i++)
            {
                sum += nums[i];
                if(nums[i] > 0) cnt++;
            }
            
    	    Console.WriteLine(Math.Ceiling(sum/cnt));
    	    
    	}
    }
}