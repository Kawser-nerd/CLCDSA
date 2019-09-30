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
            int N = int.Parse(s);
            int a = 0;
            for(int i = 0 ; i < s.Length ; i++)
            {
                a += int.Parse(s[i].ToString());
            }

            if(N%a==0)
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