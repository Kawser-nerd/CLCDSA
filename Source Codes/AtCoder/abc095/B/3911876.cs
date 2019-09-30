using System;
using System.Collections.Generic;
using System.Linq;

namespace CSharpSample01
{


    class Program
    {

        

        static void Main(string[] args)
        {

            int[] data = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
            int N = data[0];
            int X = data[1];

            int min = X;
            int sum = 0;
            for (int i = 0; i < N; i++)
            {
                int a = int.Parse(Console.ReadLine());
                if (min > a) min = a;
                sum += a;
            }

            Console.WriteLine(N + (X - sum) / min);


        }
    }
}