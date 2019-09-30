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
            string s1 = Console.ReadLine();
            string s2 = Console.ReadLine();
            
            s1 = s1.PadLeft(s2.Length, '0');
            s2 = s2.PadLeft(s1.Length, '0');

            bool equal = true;
            for(int i = 0 ; i < s1.Length ; i++)
            {
                if(s1[i] > s2[i])
                {
                    Console.WriteLine("GREATER");
                    equal = false;
                    break;
                }
                else if(s1[i] < s2[i])
                {
                    Console.WriteLine("LESS");
                    equal = false;
                    break;
                }
            }
            if(equal) Console.WriteLine("EQUAL");
        }
    }
}