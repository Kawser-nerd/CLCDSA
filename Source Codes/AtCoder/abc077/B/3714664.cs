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
            double N = double.Parse(Console.ReadLine());
            double a = 1;
            
            while(true)
            {
                if(Math.Pow(a+1,2) > N)
                {
                    break;
                }
                else
                {
                    a++;
                }
            }
            Console.WriteLine(Math.Pow(a,2));
        }
    }
}