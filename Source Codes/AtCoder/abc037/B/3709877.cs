using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace MyProgram{
    public class Program
    {	
        public static void Main(string[] args)
    	{
    	    int[] input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            int n = input[0];
            int Q = input[1];
            
            int[] nums = new int[n];
            int L,R,T;
            for(int i = 0 ; i < Q ; i++)
            {
                input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
                L = input[0];
                R = input[1];
                T = input[2];
                
                for(int j = L-1; j < R ; j++)
                {
                    nums[j] = T;
                }
            }
            
            foreach(int i in nums)
            {
                Console.WriteLine(i);
            }
    	}
    }
}