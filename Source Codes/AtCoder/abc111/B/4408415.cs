using System;
using System.Collections.Generic;

namespace CompetitiveProgramming
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());

            int quot = n / 111;
            int rest = n % 111;


            if(rest != 0)
            {
                Console.WriteLine(111 * (quot + 1));
            }else{
                Console.WriteLine(111 * quot);
            }

        }
    }
}