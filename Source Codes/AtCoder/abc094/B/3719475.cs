using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace MyProgram
{
    public class Program
    {	
        public static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int N = int.Parse(input[0]);
            int M = int.Parse(input[1]);
            int X = int.Parse(input[2]);
            
            int[] nums = new int[N+1];
            
            input = Console.ReadLine().Split(' ');
            for(int i = 0 ; i < M ; i++)
            {
                int x = int.Parse(input[i]);
                nums[x]++;
            }

            int a = 0;
            int b = 0;
            for(int i = 0 ; i <= X ; i++)
            {
                a += nums[i];
                
            }
            for(int i = X ; i <= N ; i++)
            {
                b += nums[i];
            }
            Console.WriteLine(Math.Min(a,b));
        }
    }
}