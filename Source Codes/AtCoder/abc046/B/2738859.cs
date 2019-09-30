using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.OtherPractice
{
    class ABC_046_B
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int n = int.Parse(input[0]);
            int k = int.Parse(input[1]);
            Console.WriteLine(k * Math.Pow(k - 1, n - 1));
        }
    }
}