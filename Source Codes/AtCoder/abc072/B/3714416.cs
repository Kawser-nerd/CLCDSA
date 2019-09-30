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
            string s = Console.ReadLine();
            string ss = "";
            
            for(int i = 0 ; i < s.Length ; i++)
            {
                if((i+1) % 2 == 1)
                {
                    Console.Write(s[i]);
                }
            }
            Console.WriteLine();
        }
    }
}