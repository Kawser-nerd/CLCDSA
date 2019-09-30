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
            int n = int.Parse(Console.ReadLine());
            int[] houses = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            
            int min = 999999999;
            int max = 0;
            
            for(int i = 0 ; i < n ; i++)
            {
                min = Math.Min(min, houses[i]);
                max = Math.Max(max, houses[i]);
            }
            
            Console.WriteLine(max-min);
        }
        
    }
}