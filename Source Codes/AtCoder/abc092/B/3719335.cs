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
            int N = int.Parse(Console.ReadLine());
            string[] input = Console.ReadLine().Split(' ');
            int D = int.Parse(input[0]);
            int X = int.Parse(input[1]);
            
            int ans = 0;
            
            for(int i = 0 ; i < N ; i++)
            {
                int A = int.Parse(Console.ReadLine());
                for(int j = 0 ; j < D ; j += A)
                {
                    ans++;
                }
            }
            
            Console.WriteLine(ans+X);
        }
    }
}