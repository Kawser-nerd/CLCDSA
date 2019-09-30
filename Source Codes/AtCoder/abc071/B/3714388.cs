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
            bool None = true;
            for(int i = 0 ; i < 26 ; i++)
            {
                char c = (char)(97+i);
                if(!s.Contains(c))
                {
                    Console.WriteLine(c);
                    None = false;
                    break;
                }
            }
            if(None) Console.WriteLine("None");
            

        }
        
    }
}