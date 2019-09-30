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
            bool ok = false;
            
            int a = 4;
            while(a <= n)
            {
                if((n-a)%7 == 0) ok = true;
                a += 4;
            }
            a = 7;
            while(a <= n)
            {
                if((n-a)%4 == 0) ok = true;
                a += 7;
            }
            
            if(ok) Console.WriteLine("Yes");
            else Console.WriteLine("No");
      
        }
    }
}