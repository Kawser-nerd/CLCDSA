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
            int n = int.Parse(Console.ReadLine());
            int ans = 0;
            string[] input;
            int a,b;
            for(int i = 0 ; i < n ; i++)
            {
                input = Console.ReadLine().Split(' ');
                a = int.Parse(input[0]);
                b = int.Parse(input[1]);
                
                ans += (b-a)+1;
            }
            Console.WriteLine(ans);
            
        }
    }
}