using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace MyProgram{
    public class Program
    {	
        public static void Main(string[] args)
    	{
            int n = int.Parse(Console.ReadLine());
            int x = 0;
            string s = Console.ReadLine();
            int max = 0;
            
            for(int i = 0 ; i < n ; i++)
            {
                if(s[i] == 'I')
                {
                    x++;
                }    
                else
                {
                    x--;
                }
                max = Math.Max(max,x);
            }
            Console.WriteLine(max);
    	}
    }
}