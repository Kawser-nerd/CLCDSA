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
            System.Text.StringBuilder sb = new System.Text.StringBuilder();
            
            for(int i = 0 ; i < s.Length ; i++)
            {
                if((i+1) % 2 == 1)
                {
                    sb.Append(s[i]);
                }
            }
            Console.WriteLine(sb);
        }
    }
}