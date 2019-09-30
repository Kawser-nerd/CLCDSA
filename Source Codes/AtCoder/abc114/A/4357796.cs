using System;
using System.Collections.Generic;

namespace CompetitiveProgramming
{
    class Program
    {
        static void Main(string[] args)
        {
            int x = int.Parse(Console.ReadLine());
            switch(x)
            {
                case 3:
                case 5:
                case 7:
                    Console.WriteLine("YES");
                    break;
                default:
                    Console.WriteLine("NO");
                    break;

            }
        }

    }
}