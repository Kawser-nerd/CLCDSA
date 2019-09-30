using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace MyProgram{
    public class Program
    {	
        public static void Main(string[] args)
    	{
            int[] n = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            int L = n[0];
            int H = n[1];
            int nn = int.Parse(Console.ReadLine());
            
            for(int i = 0 ; i < nn ; i++)
            {
                int t = int.Parse(Console.ReadLine());
                if(t < L)
                {
                    Console.WriteLine(L-t);
                }
                else if(t > H)
                {
                    Console.WriteLine(-1);
                }
                else
                {
                    Console.WriteLine(0);
                }
            }
    	}
    }
}