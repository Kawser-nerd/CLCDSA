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
            int[] balls = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            int ans = 0;
            int a,b;
            for(int i = 0 ; i < N ; i++)
            {
                a = balls[i] * 2;
                b = Math.Abs(balls[i]-K)*2;
                ans += Math.Min(a,b);
            }
            Console.WriteLine(ans);
        }
    }
}