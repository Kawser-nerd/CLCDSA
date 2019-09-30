using System;
using System.Collections.Generic;
using System.Linq;

namespace CSharpSample01
{
    

    class Program
    {


        static long Euclid(long a, long b)
        {
            long tmp;
            
            while(a % b != 0)
            {
                tmp = b;
                b = a % b;
                a = tmp;
                
            }

            
            return b;
        }

        static long Solve(long a, long b)
        {
            return a / Euclid(a, b) * b;
        }       

        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());

            long a;
            long b;
            a = long.Parse(Console.ReadLine());
            for(int i = 1; i < N; i++)
            {
                b = long.Parse(Console.ReadLine());
                
                if(a < b)
                {
                    long tmp = a;
                    a = b;
                    b = tmp;
                }
                
                a = Solve(a, b);
                
            }

            Console.WriteLine(a);

        }
    }
}