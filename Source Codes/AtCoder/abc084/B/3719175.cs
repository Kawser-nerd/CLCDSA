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
            int[] n = Console.ReadLine().Split(' ').Select(ss => int.Parse(ss)).ToArray();
            int A = n[0];
            int B = n[1];
            
            string s = Console.ReadLine();
            bool ok = true;
            for(int i = 0 ; i < A ;i++)
            {
                if(s[i]=='-') ok = false;
            }
            if(s[A] != '-') ok = false;
            for(int i = A+1 ; i < A+B ;i++)
            {
                if(s[i] == '-') ok = false;
            }
            
            if(ok) Console.WriteLine("Yes");
            else Console.WriteLine("No");
        }
    }
}