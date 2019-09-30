using System;
using System.Collections.Generic;
using System.Linq;

namespace CompetitiveProgramming
{
    class Program
    {
        static void Main(string[] args)
        {
            MainStream();
        }

        static void MainStream()
        {
            string[] a_b_c = Console.ReadLine().Split(' ');
            int a = int.Parse(a_b_c[0]);
            int b = int.Parse(a_b_c[1]);
            int c = int.Parse(a_b_c[2]);

            int count = b / a;

            if(count<c)
            {
                Console.WriteLine(count);
            }
            else
            {
                Console.WriteLine(c);
            }
        }



    }
}