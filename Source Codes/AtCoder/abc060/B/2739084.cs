using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.LoopSimulation
{
    class ABC_060_B
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int a = int.Parse(input[0]);
            int b = int.Parse(input[1]);
            int c = int.Parse(input[2]);

            for (int i = 0; i < b; i++)
            {
                if ((a * i) % b == c)
                {
                    Console.WriteLine("YES");
                    return;
                }
            }
            Console.WriteLine("NO");
        }
    }
}