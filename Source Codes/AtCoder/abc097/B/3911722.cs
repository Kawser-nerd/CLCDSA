using System;
using System.Collections.Generic;
using System.Linq;

namespace CSharpSample01
{


    class Program
    {

        

        static void Main(string[] args)
        {

            int X = int.Parse(Console.ReadLine());

            int max = 1;

            for(int i = 2; i <= (int)Math.Sqrt(X); i++)
            {
                int a = i;
                while(a <= X)
                {
                    a *= i;
                }

                a /= i;
                //Console.WriteLine(a);
                if (max < a) max = a;

            }

            Console.WriteLine(max);

        }
    }
}