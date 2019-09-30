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
            double n = double.Parse(input[0]+input[1]);
            
            double n1 = Math.Sqrt(n);
            double n2 = Math.Round(n1);
            
            if(n1 - n2 == 0)
            {
                Console.WriteLine("Yes");
            }
            else
            {
                Console.WriteLine("No");
            }
        }
    }
}