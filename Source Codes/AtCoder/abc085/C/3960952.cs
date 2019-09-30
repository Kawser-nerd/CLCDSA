using System;
using System.Collections.Generic;
using System.Linq;

namespace CSharpSample01
{
   
    class Program
    {
        
        static void Main(string[] args)
        {
            string[] str = Console.ReadLine().Split(' ');
            int N = int.Parse(str[0]);
            int Y = int.Parse(str[1]);


            for(int a = 0; a <= N; a++)
            {
                int s = Y - a * 10000;
                if (s < 0) continue;
                for(int b = 0; b <= N - a; b++)
                {
                    int t = s - 5000 * b;
                    int c = N - a - b;
                    if (t < 0 || t % 1000 != 0 || t / 1000 != c) continue;                   
                    else
                    {                       
                        Console.WriteLine($"{a} {b} {c}");
                        return;
                    }                               
                    
                }


            }

            Console.WriteLine("-1 -1 -1");

        }
    }
}