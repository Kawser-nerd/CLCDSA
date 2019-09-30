using System;
using System.Linq;
using System.Collections.Generic;

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

            var arr = new List<int>();

            for (int i = A; i < A + K && i <= B; i++)
                arr.Add(i);

            for (int i = B - K + 1; i <= B && i >= A ; i++)
                arr.Add(i);

            foreach (var a in arr.Distinct().ToArray())
                Console.WriteLine(a);

        }
    }
}