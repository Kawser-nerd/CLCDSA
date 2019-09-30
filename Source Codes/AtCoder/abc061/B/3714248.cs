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
            int[,] town = new int[N,N];
            
            for(int i = 0 ; i < M ; i++)
            {
                input = Console.ReadLine().Split(' ');
                int a = int.Parse(input[0])-1;
                int b = int.Parse(input[1])-1;
                
                town[a,b] += 1;
                town[b,a] += 1;
            }
            int ans;
            for(int i = 0 ; i < N ; i++)
            {
                ans = 0;
                for(int j = 0 ; j < N ; j++)
                {
                    ans += town[i,j];
                }
                Console.WriteLine(ans);
            }

        }
    }
}