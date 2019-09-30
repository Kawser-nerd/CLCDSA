using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApplication1
{

    class Program
    {

        static void Main(string[] args)
        {
            string[] str = Console.ReadLine().Split(' ');

            int n = int.Parse(str[0]);
            int m = int.Parse(str[1]);

            bool[,] data = new bool[n + 1, n + 1];
            var anser = new int[n + 1];

            int a;
            int b;           

            for(int i = 1; i < m + 1; i++)
            {
                str = Console.ReadLine().Split(' ');

                a = int.Parse(str[0]);
                b = int.Parse(str[1]);

                anser[a]++;
                anser[b]++;

            }


            for(int i= 1; i <= n; i++)
            {
                Console.WriteLine(anser[i]);
            }


        }

    }

}