using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.C_Challenge
{
    class ABC_010
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int txa = int.Parse(input[0]);
            int tya = int.Parse(input[1]);
            int txb = int.Parse(input[2]);
            int tyb = int.Parse(input[3]);
            int t= int.Parse(input[4]);
            int v = int.Parse(input[5]);
            int n = int.Parse(Console.ReadLine());
            var pos = new int[n, 2];
            for (int i = 0; i < n; i++)
            {
                input = Console.ReadLine().Split(' ');
                pos[i, 0] = int.Parse(input[0]);
                pos[i, 1] = int.Parse(input[1]);
            }

            double delta = 0.000001;//????
            for(int i = 0; i < n; i++)
            {
                double distance
                    = Math.Sqrt(Math.Pow(pos[i, 0] - txa, 2) + Math.Pow(pos[i, 1] - tya, 2));
                distance 
                    += Math.Sqrt(Math.Pow(pos[i, 0] - txb, 2) + Math.Pow(pos[i, 1] - tyb, 2));
                if (v * t >= distance - delta)
                {
                    Console.WriteLine("YES");
                    return;
                }
            }

            Console.WriteLine("NO");
        }
    }
}