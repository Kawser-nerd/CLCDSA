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
            int K = int.Parse(Console.ReadLine());

            if(K%2==1)
            {
                Console.WriteLine((K / 2) * ((K / 2) + 1));
            }
            else
            {
                Console.WriteLine((K / 2) * (K / 2));
            }
        }



    }
}