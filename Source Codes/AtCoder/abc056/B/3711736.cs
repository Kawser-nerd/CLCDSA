using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace MyProgram{
    public class Program
    {	
        public static void Main(string[] args){
            string[] s = Console.ReadLine().Split(' ');
            int W = int.Parse(s[0]);
            int a = int.Parse(s[1]);
            int b = int.Parse(s[2]);
            
            int ans = 0;
            if(a < b)
            {
                ans = b - (a + W); 
            }
            else
            {
                ans = a - (b + W);
            }
            
            
            if(ans < 0) ans = 0;
            Console.WriteLine(ans);
        }
    }
}