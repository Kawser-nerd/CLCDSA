using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.C_Challenge
{
    class ABC_012
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int margin = 2025 - n;
            int val = 0;
            for (int i = 1; i <= 9; i++)
            {
                for (int j = 1; j <= 9; j++)
                {
                    val = i * j;
                    if (val == margin)
                    {
                        Console.WriteLine(i.ToString() + " x " + j.ToString());
                    }
                }
            }
        }
    }
}