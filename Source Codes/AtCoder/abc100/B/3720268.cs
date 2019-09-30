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
            string[] str = Console.ReadLine().Split(' ');
            double D = double.Parse(str[0]);
            double N = double.Parse(str[1]);
            
            if(N%100 == 0) N++;
            double ans = Math.Pow(100,D)*N;
            
            Console.WriteLine(ans);
        }
    }
}