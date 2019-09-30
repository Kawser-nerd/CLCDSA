using System;
using System.Linq;

namespace arc006_1
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] E = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int B = int.Parse(Console.ReadLine());
            int[] L = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int x = 0;
            for (int i = 0; i < 6; i++)
            {
                if (Array.BinarySearch(L, E[i]) >= 0)
                {
                    x++;
                }
            }
            if (x == 6)
            {
                x++;
            }
            if (x == 5 && Array.BinarySearch(L, B) >= 0)
            {
                x++;
            }
            if (x >= 3)
            {
                Console.WriteLine(8 - x);
            }
            else
            {
                Console.WriteLine(0);
            }
        }
    }
}