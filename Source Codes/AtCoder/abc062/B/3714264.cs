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
            int N = int.Parse(input[0]);
            int M = int.Parse(input[1]);
            
            string s = "";
            s = s.PadLeft(M+2,'#');
            
            for(int i = 0 ; i < N+2 ; i++)
            {
                if(i==0 || i == N+1)
                {
                    Console.WriteLine(s);
                }
                else
                {
                    Console.WriteLine("#"+Console.ReadLine()+"#");
                }
            }
        }
    }
}