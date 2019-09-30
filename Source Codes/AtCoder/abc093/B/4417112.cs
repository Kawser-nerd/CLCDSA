using System;
using System.Linq;

namespace B___Small_and_Large_Integers
{
    class Program
    {
        static void Main(string[] args)
        {
            var ABK = Console.ReadLine().Split().Select(int.Parse).ToArray();
            var A = ABK[0];
            var B = ABK[1];
            var K = ABK[2];

            for (int i = A; i <= B; i++)
            {
                if (i < A + K || i > B - K)
                {
                    Console.WriteLine(i);
                }
            }

        }
    }
}