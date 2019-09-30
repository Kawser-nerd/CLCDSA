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
            int n = int.Parse(s);
            
            int x = 0;
            
            char[] c = s.ToCharArray();
            for(int i = 0 ; i < c.Length ; i++)
            {
                x += (int)(c[i]-'0');
            }
            if(n%x == 0) Console.WriteLine("Yes");
            else Console.WriteLine("No");
        }
    }
}