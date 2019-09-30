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
            string[] input = Console.ReadLine().Split(' ');
            int a = int.Parse(input[0]);
            int b = int.Parse(input[1]);
            int c = int.Parse(input[2]);
            
            bool ok = false;
            for(int i = a ; i <= a * b ; i += a)
            {
                if(i%b == c) ok = true;
            }
            if(ok) Console.WriteLine("YES");
            else Console.WriteLine("NO");
        }
    }
}