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
            int K = int.Parse(Console.ReadLine());

            int max = -1;
            int u = 0;
            for(int i = 0; i < 3; i++)
            {
                if (max < data[i])
                {
                    max = data[i];
                    u = i;
                }
            }

            data[u] *= (int)Math.Pow(2, K);

            Console.WriteLine(data[0] + data[1] + data[2]);

        }
    }
}