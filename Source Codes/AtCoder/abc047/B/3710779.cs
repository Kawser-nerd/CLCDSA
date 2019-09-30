using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace MyProgram{
    public class Program
    {	
        public static void Main(string[] args)
    	{
            int[] input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();    
            int W = input[0];
            int H = input[1];
            int N = input[2];
            int maxX = W;
            int minX = 0;
            int maxY = H;
            int minY = 0;

            int x,y,a;            
            for(int i = 0 ; i < N ; i++)
            {
                input = Console.ReadLine().Split(' ').Select(s=>int.Parse(s)).ToArray();
                x = input[0];
                y = input[1];
                a = input[2];
                if(a == 1)
                {
                    minX = Math.Max(minX,x);
                }
                else if(a == 2)
                {
                    maxX = Math.Min(maxX,x);
                }
                else if(a == 3)
                {
                    minY = Math.Max(minY,y);
                }
                else if(a == 4)
                {
                    maxY = Math.Min(maxY,y);
                }
            }
            int ansX = Math.Max(0,(maxX-minX));
            int ansY = Math.Max(0,(maxY-minY));
            
            int ans = ansX * ansY;
            Console.WriteLine(ans);
    	}
    }
}