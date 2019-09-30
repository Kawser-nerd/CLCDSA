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

            int B = 0;

            for(int i = 1; i <= b - a; i++)
            {
                B += i;
            }

            int k = B - b;

            Console.WriteLine(k);

        }
    }
}