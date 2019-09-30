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
            int K = int.Parse(Console.ReadLine());
            
            int ans = 1;
            
            for(int i = 0 ; i < N ; i++)
            {
                ans = Math.Min(ans*2, ans+K);
            }
            Console.WriteLine(ans);
        }
    }
}