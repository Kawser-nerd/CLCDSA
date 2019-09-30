using System;
using System.Collections.Generic;

namespace ConsoleApplication1
{

    class Program
    {

        static void Main(string[] args)
        {

            string[] input = Console.ReadLine().Split(' ');

            int a = int.Parse(input[0]);
            int b = int.Parse(input[1]);

            int n = int.Parse(Console.ReadLine());

            for(int i = 0; i < n; i++)
            {
                int x = int.Parse(Console.ReadLine());

                if(x < a)
                {
                    Console.WriteLine(a - x);
                }
                else if(x > b)
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