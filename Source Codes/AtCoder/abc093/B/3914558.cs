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
            int A = data[0];
            int B = data[1];
            int K = data[2];

            for(int i = A; i <= B; i++)
            {
                if (i - A < K || B - i < K) Console.WriteLine(i);

            }

            


        }
    }
}