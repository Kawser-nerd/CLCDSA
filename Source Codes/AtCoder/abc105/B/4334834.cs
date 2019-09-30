using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    { 
        static void Main(string[] args)
        {
            //[summary]B - Cakes and Donuts
            int n = int.Parse(Console.ReadLine());

            if (CanBuyCakesAndDonuts(n))
            {
                Console.WriteLine("Yes");
            }
            else
            {
                Console.WriteLine("No");
            }
        }

        static bool CanBuyCakesAndDonuts(int n)
        {
            for (int i = 0; i * 7 <= n; i++)
            {
                if ((n - i * 7) % 4 == 0)
                {
                    return true;
                }
            }

            return false;
        }
    }
}