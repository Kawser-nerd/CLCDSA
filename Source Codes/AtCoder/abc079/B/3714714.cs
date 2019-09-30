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
            long[] Luca = new long[N+1];
            
            Luca[0] = 2;
            Luca[1] = 1;
            
            for(int i = 2; i <= N ; i++)
            {
                Luca[i] = Luca[i-1] + Luca[i-2];
            }
            Console.WriteLine(Luca[N]);
        }
    }
}