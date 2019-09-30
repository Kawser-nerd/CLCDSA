using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace MyProgram{
    public class Program
    {	
        public static void Main(string[] args)
    	{
    	    int[] nums = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
    	    int n = nums[0];
    	    int A = nums[1];
            int B = nums[2];
            
            int move = 0;
            int pos = 0;
            string dir = "";
            
            string[] input;
            for(int i = 0 ; i < n ; i++)
            {
                input = Console.ReadLine().Split(' ');
                dir = input[0];
                move = int.Parse(input[1]);
                
                if(move <= A) move = A;
                else if(move >= B) move = B;
                if(dir == "West") move *= -1;
                pos += move;
            }
            if(pos < 0)
            {
                Console.WriteLine("West "+Math.Abs(pos));
            }
            else if(pos > 0)
            {
                Console.WriteLine("East "+pos);
            }
            else
            {
                Console.WriteLine(0);
            }
        
    	}
    }
}