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
            int[] n = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            
            int X = n[0];
            int Y = n[1];
            int Z = n[2];
            
            Console.WriteLine((X-Z)/(Y+Z));
        }
    }
}