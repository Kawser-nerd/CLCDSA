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
            int X = int.Parse(input[1]);
            
            List<int> donuts = new List<int>();
            for(int i = 0 ; i < N ; i++)
            {
                donuts.Add(int.Parse(Console.ReadLine()));
            }
            
            int a = donuts.Sum();
            donuts.Sort();
            
            Console.WriteLine(N + ((X - a)/donuts[0]));
        }
    }
}