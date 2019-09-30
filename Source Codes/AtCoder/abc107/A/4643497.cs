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
            string[] n_i = Console.ReadLine().Split();
            Console.WriteLine(int.Parse(n_i[0]) - int.Parse(n_i[1]) + 1);
        }



    }
}